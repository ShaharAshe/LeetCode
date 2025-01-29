class leetcode_100_Same_Tree
{
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null)
        {
            return true;
        }
        if((p == null || q == null) || p.val != q.val)
        {
            return false;
        }
        boolean b1 = isSameTree(p.left, q.left),
                b2 = isSameTree(p.right, q.right);
        return (b1 && b2);
    }
    
    public static void main(String[] args)
    {
        TreeNode p = new TreeNode(1, new TreeNode(2), new TreeNode(3)),
                 q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
        boolean result =  new leetcode_100_Same_Tree().isSameTree(p, q);
        System.out.println(result);
    }
}


 
