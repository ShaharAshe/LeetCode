/* -- Id = 199 -- */

#include <iostream>
#include <vector>
#include <queue>

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

std::vector<int> rightSideView(TreeNode* root) {
    std::queue<TreeNode*> q;
    std::vector<int> v;

    if (root)
        q.emplace(root);
    
    while (!q.empty()){
        v.emplace_back(q.back()->val);
        int s = q.size();
        for (size_t i = 0; i < s; ++i)
        {
            int l = q.front()->val;
            if(q.front()->left)
            {
                q.emplace(q.front()->left);
            }
            if (q.front()->right)
            {
                q.emplace(q.front()->right);
            }
            q.pop();
        }
    }

    return v;
}

int main(int argc, char const *argv[])
{
    // [1,2,3,null,5,null,4]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    root->left->left = nullptr;
    root->right->left = nullptr;

    std::vector<int> v = rightSideView(root);
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    
    return 0;
}
