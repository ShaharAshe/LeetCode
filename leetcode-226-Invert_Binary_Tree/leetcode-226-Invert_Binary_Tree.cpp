#include <iostream>
#include <cstdlib>
#include <queue> // for print

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        
        auto res_t = new TreeNode();
        res_t->val = root->val;
        
        res_t->right = invertTree(root->left);
        res_t->left = invertTree(root->right);
        return res_t;
    }
};

void deleteTree(TreeNode* root) {
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    auto res = Solution().invertTree(root);
    
    // print
    auto run = res;
    std::cout << "[";
    std::queue<TreeNode*> q;
        q.push(run);    
        while (!q.empty()) {
            int levelSize = q.size();  
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();  
                std::cout << node->val;
                q.pop();
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if(q.size() != 0) std::cout << ", ";
            }
        }
    std::cout << "]" << std::endl;
    
    deleteTree(root);
    root = nullptr;
    deleteTree(res);
    res = nullptr;
    
    return EXIT_SUCCESS;
}