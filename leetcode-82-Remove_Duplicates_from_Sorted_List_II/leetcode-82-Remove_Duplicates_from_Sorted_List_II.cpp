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
    ListNode* deleteDuplicates(ListNode* head) {
        auto chop = head,
             runner = head;

        while(runner && runner->next)
        {
            if(runner->val == runner->next->val)
            {
                while((runner && runner->next) && (runner->val == runner->next->val))
                {
                    auto temp_val = runner;
                    if(runner == head) {
                        chop = temp_val->next;
                        head = chop;
                        runner = head;
                    } else {
                        chop->next = temp_val->next;
                        runner = chop->next;
                    }
                    
                    delete temp_val;
                }
                auto temp_val = runner;
                if(runner == head) {
                    chop = (temp_val)?temp_val->next:nullptr;
                    head = chop;
                    runner = head;
                } else {
                    chop->next = (temp_val)?temp_val->next:nullptr;
                    runner = chop->next;
                }
                delete temp_val;
            }
            else
            {
                if(chop == runner) {
                    runner = runner->next;
                } else {
                    chop = chop->next;
                    runner = runner->next;
                }
            }
        }
        return head;
    }
};


int main() {
    ListNode* head = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(3,new ListNode(4,new ListNode(4,new ListNode(5)))))));
    auto res = Solution().deleteDuplicates(head);
    
    auto runner = res;
    std::cout << "[";
    while (runner)
    {
        std::cout << runner->val;
        if(runner->next)
            std::cout << ",";
        runner = runner->next;
    }
    std::cout << "]" << std::endl;
    
    
    return EXIT_SUCCESS;
}