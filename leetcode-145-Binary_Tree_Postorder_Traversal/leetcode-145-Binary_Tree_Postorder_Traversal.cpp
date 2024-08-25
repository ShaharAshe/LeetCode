#include <iostream>
#include <cstdlib>
#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void postorder(TreeNode* root, std::vector<int>& res){
    if(!root)
    {
        return;
    }
    postorder(root->left,res);
    postorder(root->right,res);
    res.emplace_back(root->val);
}
std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> post_res;
    postorder(root, post_res);
    return post_res;
}


int main(){
    TreeNode* root = nullptr;
    // [1,null,2,3]
    root = new TreeNode(1);
    root->left = nullptr;
    root->right = new TreeNode(2);

    root->right->left = new TreeNode(3);
    root->right->right = nullptr;

    root->right->left->left = nullptr;
    root->right->left->right = nullptr;

    std::vector<int> res = postorderTraversal(root);

    std::cout << "[" ;
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i];
        if(i != res.size()-1){
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return EXIT_SUCCESS;
}