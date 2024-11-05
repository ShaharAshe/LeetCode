from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        if not p or not q or p.val != q.val:
            return False
        v1 = self.isSameTree(p.left, q.left)
        v2 = self.isSameTree(p.right, q.right)
        return True if v1 and v2 else False
    

if __name__ == "__main__":
    # p: TreeNode = TreeNode(1, TreeNode(2), TreeNode(3))
    # q: TreeNode = TreeNode(1, TreeNode(2), TreeNode(3))

    # p: TreeNode = TreeNode(1, TreeNode(2))
    # q: TreeNode = TreeNode(1, None, TreeNode(2))

    p: TreeNode = TreeNode(1, TreeNode(2), TreeNode(1))
    q: TreeNode = TreeNode(1, TreeNode(1), TreeNode(2))

    res: bool = Solution().isSameTree(p, q)

    print(res)
