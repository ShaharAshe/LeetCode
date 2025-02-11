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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!(root->left)&&!(root->right)&&!(targetSum-(root->val))) return true;
        
        return hasPathSum(root->left, (targetSum-(root->val))) || hasPathSum(root->right, (targetSum-(root->val)));
    }
};


int main(){
    TreeNode* root = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr), new TreeNode(8, new TreeNode(13), new TreeNode(4, nullptr,new TreeNode(1))));
    int targetSum = 22;
    
    auto res = Solution().hasPathSum(root, targetSum);
    
    std::cout << ((res)? "true" : "false") << std::endl;

    return EXIT_SUCCESS;
}