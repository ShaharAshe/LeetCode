#include <iostream>
#include <cstdlib>
#include <stack>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::stack<ListNode*> vals;
        
        vals.push(head);
        while(!vals.empty() && vals.top())
        {
            vals.push(vals.top()->next);
        }
        
        size_t vals_size = vals.size();
        for(size_t i = 0; i<vals_size/2; ++i)
        {
            vals.pop();
            if (head->val != vals.top()->val) {
                return false;
            }
            head = head->next;
        }
        return true;
    }
};


int main(){
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));

    auto res = Solution().isPalindrome(head);
    
    if(res) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return EXIT_SUCCESS;
}