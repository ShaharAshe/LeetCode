#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) : _inVals(), _currIndex(0) { inOrderTraveler(root); }
    
    int next() {
        if(this->_inVals.size()<=(this->_currIndex)) return -1;
        return this->_inVals[this->_currIndex++];
    }
    
    bool hasNext() {
        if(this->_inVals.size()<=(this->_currIndex)) return false;
        return true;
    }
private:
    std::vector<int> _inVals;
    int _currIndex;

    void inOrderTraveler(TreeNode* root){
        if(!root) return;
        inOrderTraveler(root->left);
        this->_inVals.emplace_back(root->val);
        inOrderTraveler(root->right);
    }
};

int main() {
    TreeNode* root = new TreeNode(7,new TreeNode(3),new TreeNode(15,new TreeNode(9),new TreeNode(20)));
    BSTIterator bSTIterator = BSTIterator(root);
    std::vector<std::string> optToRun = {"next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"};

    std::cout << "[null";
    for (auto &s : optToRun) {
        if (s == "next") {
            std::cout <<','<<bSTIterator.next();
        } else if(s == "hasNext") {
            std::cout <<','<<((bSTIterator.hasNext())?"true":"false");
        } else {
            continue;
        }
    }
    std::cout<<']'<<std::endl;

    return EXIT_SUCCESS;
}