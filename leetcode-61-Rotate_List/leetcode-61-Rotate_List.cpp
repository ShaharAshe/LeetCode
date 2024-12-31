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
    ListNode* rotateRight(ListNode* head, int k) {
        int temp_k = 0;
        auto run = head;
        while(run)
        {
            run = run->next;
            ++temp_k;
        }
        run = head;
        temp_k = (temp_k)?(k%temp_k):0;
        if(!temp_k || !head || !head->next) return head;
        while(temp_k && run)
        {
            run = run->next;
            --temp_k;
        }
        
        auto slow = head;
        while(run && run->next)
        {
            slow = slow->next;
            run = run->next;
        }

        auto temp_head = slow->next;
        run->next = head;
        head = temp_head;
        slow->next = nullptr;

        return head;
    }
};


int main(){
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int k = 2;

    auto res = Solution().rotateRight(head, k);
    
    auto run = res;
    std::cout << "[";
    while(run)
    {
        std::cout << run->val;
        if (run->next) std::cout << ", ";
        run = run->next;
    }
    std::cout << "]" << std::endl;
    
    return EXIT_SUCCESS;
}