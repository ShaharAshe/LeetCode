import java.util.*;

public class leetcode_106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal {
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
        private final Map<Integer,Integer> inorderMap = new HashMap<>();
        
        public TreeNode buildTree(int[] inorder, int[] postorder) {
            for (int i = 0; i < inorder.length; ++i) {
                inorderMap.put(inorder[i], i);
            }
            return buildTree(postorder,0,inorder.length,0,postorder.length);
        }
        
        private TreeNode buildTree(int[] postorder, int startI, int endI, int startP, int endP){
            if(endI<=startI||endP<=0) return null;
            return new TreeNode(postorder[endP-1],buildTree(postorder, startI, inorderMap.get(postorder[endP-1]), startP, startP+(inorderMap.get(postorder[endP-1])-startI)),buildTree(postorder, inorderMap.get(postorder[endP-1])+1, endI, startP+(inorderMap.get(postorder[endP-1])-startI), endP-1));
        }
    }

    public static void main(String[] args) {
        int[] inorder = new int[]{9,3,15,20,7};
        int[] postorder = new int[]{9,15,7,20,3};
        TreeNode root = new Solution().buildTree(inorder, postorder);
        
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