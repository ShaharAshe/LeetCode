#include <iostream>
#include <cstdlib>
#include <vector>


class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void postorder_rec(Node* root, std::vector<int>& res){
    if(!root)
        return;
    
    for(auto x:root->children){
        postorder_rec(x, res);
    }
    res.emplace_back(root->val);
}

std::vector<int> postorder(Node* root) {
    std::vector<int> res;
    postorder_rec(root, res);
    return res;
}


int main(){
    // [1,null,3,2,4,null,5,6]
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node3 = new Node(3, {node5, node6});
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    Node* root = new Node(1, {node3, node2, node4});

    std::vector<int> res = postorder(root);

    std::cout << "[" ;
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i];
        if(i != res.size()-1){
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return EXIT_SUCCESS;
}