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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT32_MIN;
        maxPathSum(root, maxSum);
        return maxSum;
    }
    int maxPathSum(TreeNode* root, int &maxSum) {
        if(!root) return 0;
        int sL = maxPathSum(root->left, maxSum);
        sL = (sL<0)?0:sL;
        int sR = maxPathSum(root->right, maxSum);
        sR = (sR<0)?0:sR;
        maxSum = std::max(maxSum,(root->val+sL+sR));
        return (std::max(sL,sR)+root->val);
    }
};

int main() {
    TreeNode* root = new TreeNode(-10,new TreeNode(9),new TreeNode(20,new TreeNode(15),new TreeNode(7)));
    
    auto res = Solution().maxPathSum(root);
    
    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}