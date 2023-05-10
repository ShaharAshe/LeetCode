/* -- Id = 100 -- */

#include <iostream>
#include <string>

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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q)
        return true;
    if ((p != nullptr && q == nullptr)||
        (p == nullptr && q != nullptr)||
        (p->val != q->val))
        return false;
    
    return !(!isSameTree(p->left, q->left)||
       !isSameTree(p->right, q->right));
}

int main(int argc, char const *argv[])
{
    TreeNode* root1 = new TreeNode;
    TreeNode* tl1 = new TreeNode;
    TreeNode* tl2 = new TreeNode;

    root1->val = 1;
    tl1->val = 2;
    tl2->val = 1;

    root1->left = tl1;
    root1->right = tl2;
    
    tl1->left = tl1->right = nullptr;
    tl2->left = tl2->right = nullptr;

    TreeNode* root2 = new TreeNode;
    TreeNode* tr1 = new TreeNode;
    TreeNode* tr2 = new TreeNode;

    root2->val = 1;
    tr1->val = 1;
    tr2->val = 2;

    root2->left = tr1;
    root2->right = tr2;

    tr1->left = tr1->right = nullptr;
    tr2->left = tr2->right = nullptr;

    std::cout << isSameTree(root1, root2) << std::endl;
    return 0;
}
