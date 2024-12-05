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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        auto first_back = head;
        size_t i_pos = 1;
        while(first_back && ((i_pos++)+1)<left)
        {
            first_back = first_back->next;
        }
        i_pos = left;

        auto left_point = (left == 1)?first_back:first_back->next,
             mid_point = left_point->next,
             right_point = (mid_point)?mid_point->next:nullptr;
        
        if(!mid_point)
        {
            head = left_point;
            head->next = first_back;
            first_back->next = nullptr;
            return head;
        }
        while((i_pos++) < right)
        {
            left_point->next = right_point;
            if(left == 1) {
                mid_point->next = head;
                head = mid_point;
            } else {
                mid_point->next = first_back->next;
                first_back->next = mid_point;
            }
            mid_point = right_point;
            right_point = (right_point)?right_point->next:nullptr;
        }
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    int left = 2;
    int right = 4;

    auto res = Solution().reverseBetween(head, left, right);

    std::cout << '[';
    auto temp_pos = res;
    while(temp_pos) {
        std::cout << temp_pos->val;
        if(temp_pos->next) std::cout << ", ";
        temp_pos = temp_pos->next;
    }
    std::cout << ']' << std::endl;
    
    return EXIT_SUCCESS;
}