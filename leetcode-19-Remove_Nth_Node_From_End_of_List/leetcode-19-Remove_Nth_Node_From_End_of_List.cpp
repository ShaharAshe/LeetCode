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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        auto pos_end = head;
        ++n;
        while(pos_end && n)
        {
            pos_end = pos_end->next;
            --n;
        }
        auto pos = head;
        while(pos_end)
        {
            pos_end = pos_end->next;
            pos = pos->next;
        }
        ListNode* pos_del = nullptr;
        if(!n && pos->next) {
            pos_del = pos->next;
            pos->next = pos_del->next;
        } else {
            pos_del = head;
            head = head->next;
        }
        delete pos_del;
        return head;
    }
};


int main(){
    ListNode* s = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    int n = 2;
    
    auto res = Solution().removeNthFromEnd(s, n);

    auto pos = res;
    while(pos)
    {
        std::cout << pos->val << " ";
        pos = pos->next;
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}