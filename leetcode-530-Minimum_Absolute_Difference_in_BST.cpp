/* -- Id = 530 -- */

#include <cstdlib>
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

int check_min(TreeNode* root)
{
    int min = -1;
    if (root && root->left)
    {
        TreeNode* temp_root = root->left;
        while (temp_root->right)
                temp_root = temp_root->right;
        
        min = root->val - temp_root->val;
    }
    if (root && root->right)
    {
        TreeNode* temp_root = root->right;
        while (temp_root->left)
                temp_root = temp_root->left;

        int temp_min = temp_root->val - root->val;
        if (temp_min < min || min == -1)
            min = temp_min;
    }
    return min;
}
// -----------------------------------------------------
int getMinimumDifference(TreeNode* root) {
    if (!root)
        return -1;

    int minl = getMinimumDifference(root->left);
    int minr = getMinimumDifference(root->right);
    
    int min = check_min(root);
    if (minl != -1 && (minl < min))
        min = minl;
    if (minr != -1 && (minr < min))
        min = minr;
        
    return min;
}

int main(int argc, char const *argv[])
{
    // [4,2,6,1,3]
    // TreeNode *root = new TreeNode(4);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(6);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);
    // root->left->left->left = nullptr;
    // root->left->left->right = nullptr;
    // root->left->right->left = nullptr;
    // root->left->right->right = nullptr;
    // root->right->left = nullptr;
    // root->right->right = nullptr;

    // [543,384,652,null,445,null,699]
    TreeNode *root = new TreeNode(543);
    root->left = new TreeNode(384);
    root->right = new TreeNode(652);
    root->left->left = nullptr;
    root->left->right = new TreeNode(445);
    root->left->right->left = nullptr;
    root->left->right->right = nullptr;
    root->right->left = nullptr;
    root->right->right = new TreeNode(699);
    root->right->right->left = nullptr;
    root->right->right->right = nullptr;

    std::cout << getMinimumDifference(root) << std::endl;
    
    return EXIT_SUCCESS;
}
