#include <iostream>
#include <cstdlib>


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
        ListNode *half = nullptr,
                 *runner = head;
        while(runner && runner->next)
        {
            runner = runner->next->next;
            ListNode *temp = head;
            head = head->next;
            temp->next = half;
            half = temp;
        }
        if(runner)
        {
            head = head->next;
        }
        
        while(head && half)
        {
            if(head->val != half->val)
            {
                return false;
            }
            head = head->next;
            half = half->next;
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