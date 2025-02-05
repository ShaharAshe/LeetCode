import java.util.*;

public class leetcode_105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal {
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
        private final Map<Integer, Integer> indexMap = new HashMap<>();

        public TreeNode buildTree(int[] preorder, int[] inorder) {
            for(int i = 0; i < inorder.length; ++i) {
                this.indexMap.put(inorder[i],i);
            }
            return buildTree(preorder, 0, inorder.length, 0);
        }

        private TreeNode buildTree(int[] preorder, int startI, int endI, int startP) {
            if(endI<=startI||preorder.length<=startP) return null;
            if((endI-startI)<=1) return new TreeNode(preorder[startP]);
            return new TreeNode(preorder[startP], buildTree(preorder, startI, this.indexMap.get(preorder[startP]), startP+1), buildTree(preorder, this.indexMap.get(preorder[startP])+1, endI, startP+1+(this.indexMap.get(preorder[startP])-startI)));
        }
    }

    public static void main(String[] args) {
        int[] preorder = new int[]{3,9,20,15,7};
        int[] inorder = new int[]{9,3,15,20,7};
        TreeNode root = new Solution().buildTree(preorder, inorder);

        // print
        if (root == null) {
            System.out.println("[]");
        } else {
            System.out.print("[");
            Queue<TreeNode> queue = new LinkedList<>();
            queue.add(root);
            List<String> result = new ArrayList<>();
            while (!queue.isEmpty()) {
                TreeNode node = queue.poll();
                if (node != null) {
                    System.out.print(String.valueOf(node.val));
                    queue.add(node.left);
                    queue.add(node.right);
                } else {
                    System.out.print("null");
                }
                if (queue.size() > 0) {
                    System.out.print(",");
                }
            }
            System.out.println("]");
        }
    }
}