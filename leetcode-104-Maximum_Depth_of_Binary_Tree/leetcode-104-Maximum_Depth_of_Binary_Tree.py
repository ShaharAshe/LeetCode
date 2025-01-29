from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        l1: int = self.maxDepth(root.left)+1
        l2: int = self.maxDepth(root.right)+1

        return max(l1,l2)


if __name__ == "__main__":
    root: TreeNode = TreeNode(3,TreeNode(9),TreeNode(20,TreeNode(15),TreeNode(7)))
    res: int = Solution().maxDepth(root)
    
    print(res)
