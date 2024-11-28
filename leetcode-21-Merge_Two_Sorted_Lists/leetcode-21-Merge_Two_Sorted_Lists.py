from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        res: Optional[ListNode] = None
        temp_pos: Optional[ListNode] = None
        while list1 or list2:
            if not res:
                res = ListNode()
                temp_pos = res
            else:
                temp_pos.next = ListNode()
                temp_pos = temp_pos.next
            if (not list2) or (list1 and list1.val <= list2.val):
                temp_pos.val = list1.val
                list1 = list1.next
            elif list2:
                temp_pos.val = list2.val
                list2 = list2.next
        return res


if __name__ == '__main__':
    list1: Optional[ListNode] = ListNode(1, ListNode(2, ListNode(4)))
    list2: Optional[ListNode] = ListNode(1, ListNode(3, ListNode(4)))

    res: Optional[ListNode] = Solution().mergeTwoLists(list1, list2)

    temp_pos: Optional[ListNode] = res
    print('[', end='')
    while temp_pos:
        print(temp_pos.val, end='')
        temp_pos = temp_pos.next
        if temp_pos:
            print(', ', end='')
        else:
            print(']')
