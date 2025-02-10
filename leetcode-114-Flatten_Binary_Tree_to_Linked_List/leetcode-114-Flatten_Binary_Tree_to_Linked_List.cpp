#include <iostream>
#include <cstdlib>
#include <queue>

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
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);
        if(root->left) {
            auto tempR = root->left;
            while(tempR->right){
                tempR = tempR->right;
            }

            tempR->right = root->right;
            root->right = root->left;

            root->right->left = nullptr;
            root->left = nullptr;
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, nullptr ,new TreeNode(6)));
    
    Solution().flatten(root);

    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto run = q.front();
        q.pop();
        if(!run) {
            std::cout << "null";
        } else {
            std::cout << run->val;
            q.push(run->left);
            q.push(run->right);
        }
        if(!q.empty()) std::cout << ",";
    }

    return EXIT_SUCCESS;
}