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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        return reverseKGroup(head, head, k);
    }

private:
    ListNode* reverseKGroup(ListNode* head, ListNode* pos, int k) {
        auto temp_pos = pos;
        auto count_k = k;
        while(count_k)
        {
            if(!temp_pos) return pos;
            temp_pos = temp_pos->next;
            --count_k;
        }
        auto left = pos,
             mid = left->next,
             right = mid->next;
        count_k = (k-1);
        while(count_k)
        {
            left->next = right;
            mid->next = pos;

            pos = mid;
            mid = right;
            right = (right)?right->next:nullptr;
            --count_k;
        }
        auto res = reverseKGroup(head, mid, k);
        left->next = res;
        return pos;
    }
};


int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    int k = 2;
    
    auto res = Solution().reverseKGroup(head, k);
    
    auto runner = res;

    while(runner){
        std::cout << runner->val << " ";
        runner = runner->next;
    }
    std::cout << std::endl;
    return 0;
}