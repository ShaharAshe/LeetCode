#include <iostream>
#include <cstdlib>
#include <unordered_map>


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> node_map;

        auto temp_head = head;
        while(temp_head) {
            node_map[temp_head] = new Node(temp_head->val);
            temp_head = temp_head->next;
        }

        Node *res = nullptr,
             *ruuner = nullptr;
        temp_head = head;
        while(temp_head)
        {
            if (!res)
            {
                res = node_map[temp_head];
                ruuner = res;
            }
            
            ruuner->next = node_map[temp_head->next];
            ruuner->random = node_map[temp_head->random];
            
            ruuner = ruuner->next;
            temp_head = temp_head->next;
        }

        return res;
    }
};


int main(){
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->random = head->next->next->next->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    auto res = Solution().copyRandomList(head);

    auto runner = res;

    std::cout<<'[';
    while(runner) {
        std::cout<<'['<<runner->val<<',';
        if(runner->random)
            std::cout<<runner->random->val;
        else
            std::cout<<"null";
        std::cout<<']';
        runner = runner->next;
    }
    std::cout<<']'<<std::endl;

    return EXIT_SUCCESS;
}