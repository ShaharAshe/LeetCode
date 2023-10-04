/* -- Id = 141 -- */

#include <iostream>

// ====================================
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// ====================================

bool hasCycle(ListNode *head) {
    ListNode *temp_lazy = head,
             *temp_fast = head;
             
    while (temp_fast && temp_fast->next && temp_fast->next->next)
    {
        temp_lazy = temp_lazy->next;
        temp_fast = temp_fast->next->next;
        
        if(temp_fast == temp_lazy || temp_fast->next == temp_lazy)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    //[3,2,0,-4]
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    //head->next->next->next->next = nullptr;
    
    std::cout << hasCycle(head) << std::endl;
    return 0;
}


