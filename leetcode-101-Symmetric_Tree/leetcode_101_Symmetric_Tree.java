public class leetcode_101_Symmetric_Tree
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
    
    static class Solution {
        public boolean isSymmetric(TreeNode root) {
            if(root==null) return true;
            return isSymmetric(root.left,root.right);
        }

        private boolean isSymmetric(TreeNode rootL,TreeNode rootR) {
            if(rootL==null&&rootR==null) return true;
            if((rootL!=null&&rootR==null)||(rootL==null&&rootR!=null)) return false;
            if(rootL.val != rootR.val) return false;
            
            return (isSymmetric(rootL.right,rootR.left)&&isSymmetric(rootL.left,rootR.right));
        }
    }
    
    public static void main(String[] args)
    {
        TreeNode root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
        boolean result = new Solution().isSymmetric(root);
        System.out.println(result);
    }
}