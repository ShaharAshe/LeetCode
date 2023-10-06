/* -- Id = 104 -- */

#include <iostream>

// ============================================================================================
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
// ============================================================================================

int maxDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;
        
    int depth_l = maxDepth(root->left)+1;
    int depth_r = maxDepth(root->right)+1;

    return (depth_l>depth_r)? depth_l : depth_r;
}

int main(int argc, char const *argv[])
{
    // [3,9,20,null,null,15,7]
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    root->right->left->left = nullptr;
    root->right->left->right = nullptr;
    root->right->right->left = nullptr;
    root->right->right->right = nullptr;

    std::cout << maxDepth(root) << std::endl;
    
    return 0;
}
