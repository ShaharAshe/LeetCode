from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
        
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        lazy = fast = head
        while fast and fast.next:
            if fast.next is not lazy:
                fast = fast.next.next
                lazy = lazy.next
            else:
                return True
        return False


if __name__ == "__main__":
    head: ListNode = ListNode(3)
    head.next = ListNode(2)
    head.next.next = ListNode(0)
    head.next.next.next = ListNode(-4)
    head.next.next.next.next = head.next
    
    res: bool = Solution().hasCycle(head)    

    print(res)
