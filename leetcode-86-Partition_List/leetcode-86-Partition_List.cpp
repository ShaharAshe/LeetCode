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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        auto begin = head,
             run = head;
        
        while(run->next)
        {
            if(((run->next)->val)<x)
            {
                auto temp = run->next;
                if (begin->next == temp->next) {
                    run = run->next;
                    continue;
                }
                run->next = temp->next;
                if((begin == head) && (begin->val>=x)) {
                    temp->next = head;
                    head = temp;
                    begin = head;
                } else {
                    temp->next = begin->next;
                    begin->next = temp;
                    begin = begin->next;
                } 
            } else {
                run = run->next;
            }
        }
        return head;
    }
};


int main() {
    ListNode* head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
    int x = 3;
    
    auto res = Solution().partition(head, x);

    auto runner = res;
    std::cout << "[";
    while(runner)
    {
        std::cout << runner->val;
        runner = runner->next;
        if(runner)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return EXIT_SUCCESS;
}