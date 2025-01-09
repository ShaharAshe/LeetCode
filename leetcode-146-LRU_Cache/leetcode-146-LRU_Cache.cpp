#include <iostream>
#include <cstdlib>
#include <unordered_map>


class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity), _count(0), _is_full(false), _nodes(nullptr){}
    
    int get(int key) {
        if(this->_map_nodes.find(key)==this->_map_nodes.end()) return -1;
        ListNode* temp_resent_use = nullptr;
        temp_resent_use = this->_map_nodes[key];
        temp_resent_use->back->next = temp_resent_use->next;
        temp_resent_use->next->back = temp_resent_use->back;
        
        if(temp_resent_use == this->_nodes) this->_nodes = this->_nodes->next;
        if(this->_capacity==1) this->_nodes = nullptr;
        add_node(temp_resent_use);
        
        return temp_resent_use->val;
    }
    
    void put(int key, int value) {
        if(this->get(key)!=-1) {
            this->_map_nodes[key]->val = value;
            return;
        } else if(this->_is_full) {
            this->_map_nodes.erase(this->_nodes->key);
            auto temp_del = this->_nodes;
            this->_nodes = this->_nodes->next;
            this->_nodes->back = temp_del->back;
            temp_del->back->next = this->_nodes;

            delete temp_del;
            temp_del = nullptr;
            if(this->_capacity==1) this->_nodes = nullptr;
        } else if((++this->_count)==this->_capacity) {
            this->_is_full = true;
        }
        
        ListNode* temp_node = new ListNode(key, value);
        add_node(temp_node);
        this->_map_nodes[key] = temp_node;
    }

private:
struct ListNode {
        int key,
            val;
        ListNode *next,
                 *back;
        ListNode(int key, int val) : key(key), val(val), next(nullptr), back(nullptr){}
    };
    void add_node(ListNode* new_node)
    {
        if(!this->_nodes) {
            this->_nodes = new_node;
            this->_nodes->next = this->_nodes;
            this->_nodes->back = this->_nodes;
        } else {
            new_node->next = this->_nodes;
            new_node->back = this->_nodes->back;
            this->_nodes->back->next = new_node;
            this->_nodes->back = new_node;
        }
    }
    ListNode* _nodes;
    std::unordered_map<int, ListNode*> _map_nodes;
    const size_t _capacity;
    size_t _count;
    bool _is_full;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main(){
    int capacity = 2;
    LRUCache* obj = new LRUCache(capacity);
    obj->put(1, 1);
    obj->put(2, 2);
    std::cout << obj->get(1) << std::endl;
    obj->put(3, 3);
    std::cout << obj->get(2) << std::endl;
    obj->put(4, 4);
    std::cout << obj->get(1) << std::endl;
    std::cout << obj->get(3) << std::endl;
    std::cout << obj->get(4) << std::endl;
    
    return EXIT_SUCCESS;
}