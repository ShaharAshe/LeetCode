#include <iostream>
#include <cstdlib>

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
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
    int sumNumbers(TreeNode* root, int sum) {
        if(!root) return 0;
        if(!root->left && !root->right) return ((sum*10)+(root->val));
        return sumNumbers(root->left,((sum*10)+(root->val)))+sumNumbers(root->right,((sum*10)+(root->val)));
    }
};

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    
    auto res = Solution().sumNumbers(root);

    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}