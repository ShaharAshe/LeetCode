/* -- Id = 94 -- */

#include <cstdlib>
#include <iostream>
#include <vector>

// Definition for a binary tree node.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void addTovecF(std::vector<int> &vec, TreeNode* root)
{
    if(root == nullptr)
        return;
    else {
        addTovecF(vec, root->left);
        vec.push_back(root->val);
        addTovecF(vec, root->right);
    }
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> vec;
    addTovecF(vec, root);
    return vec;
}

int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode;
    TreeNode* t1 = new TreeNode;
    TreeNode* t2 = new TreeNode;

    root->val = 1;
    t1->val = 2;
    t2->val = 3;

    root->left = nullptr;
    root->right = t1;
    t1->left = t2;
    t1->right = nullptr;
    
    t2->left = t2->right = nullptr;
    
    std::vector<int> v = inorderTraversal(root);

    for (auto &i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}
