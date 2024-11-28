from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res: Optional[ListNode] = None
        temp_pos: Optional[ListNode] = None
        while l1 or l2:
            if not res:
                res = ListNode(0)
                temp_pos = res
            else:
                temp_pos.next = ListNode(temp_pos.val//10)
                temp_pos.val %= 10
                temp_pos = temp_pos.next
            if l1:
                temp_pos.val += l1.val
                l1 = l1.next
            if l2:
                temp_pos.val += l2.val
                l2 = l2.next
        if 10<=temp_pos.val:
            temp_pos.next = ListNode(temp_pos.val//10)
            temp_pos.val %= 10
        return res


if __name__ == "__main__":
    l1: Optional[ListNode] = ListNode(2, ListNode(4, ListNode(3)))
    l2: Optional[ListNode] = ListNode(5, ListNode(6, ListNode(4)))
    
    res: Optional[ListNode] = Solution().addTwoNumbers(l1, l2)

    temp_pos: Optional[ListNode] = res
    print("[", end="")
    while temp_pos:
        print(temp_pos.val, end="")
        if temp_pos.next:
            print(", ", end="")
        else:
            print("]")
        temp_pos = temp_pos.next
