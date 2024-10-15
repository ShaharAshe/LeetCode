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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *merge_lst = nullptr,
                 *add_lst = nullptr;
        
        while(list1 || list2)
        {
            if(!merge_lst) {
                merge_lst = new ListNode;
                add_lst = merge_lst;
            } else {
                add_lst->next = new ListNode;
                add_lst = add_lst->next;
            }
            add_lst->next = nullptr;

            if(!list2 || (list1 && list1->val < list2->val))
            {
                add_lst->val = list1->val;
                list1 = list1->next;
            } else {
                add_lst->val = list2->val;
                list2 = list2->next;
            }
        }
        return merge_lst;
    }
};


int main(){
    ListNode *list1 = nullptr,
             *list2 = nullptr;
    
    list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    auto res = Solution().mergeTwoLists(list1, list2);

    std::cout << "[" ;
    auto tmp = res;
    while(tmp) {
        std::cout << tmp->val ;
        if(tmp->next)
        {
            std::cout << ", ";
        }
        tmp = tmp->next;
    }
    std::cout << "]" << std::endl;

    return EXIT_SUCCESS;
}