import java.util.*;

public class leetcode_117_Populating_Next_Right_Pointers_in_Each_Node_II {
    static class Node {
        public int val;
        public Node left;
        public Node right;
        public Node next;

        public Node() {}
        public Node(int _val) {val = _val;}
        public Node(int _val, Node _left, Node _right, Node _next) {
            val = _val;
            left = _left;
            right = _right;
            next = _next;
        }
    };

    static class Solution {
        public Node connect(Node root) {
            if(root == null) return root;
            Queue<Node> levelQueue = new LinkedList<>();
            levelQueue.add(root);
            int qSize = 1;
            while (!levelQueue.isEmpty()) {
                Node cur = levelQueue.poll();
                if(cur.left != null) levelQueue.add(cur.left);
                if(cur.right != null) levelQueue.add(cur.right);
                if((--qSize)==0){
                    qSize = levelQueue.size();
                } else {
                    cur.next = levelQueue.peek();
                }
            }
            return root;
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1,new Node(2,new Node(4),new Node(5),null),new Node(3, null, new Node(7),null),null);
        Node result = new Solution().connect(root);

        Node tempRoot = result;
        // print
        System.out.print("[");
        while (tempRoot != null) {
            Node temp = tempRoot;
            while (temp != null) {
                System.out.print(temp.val);
                temp = temp.next;
                if (tempRoot.left != null||temp!=null) {
                    System.out.print(",");
                }
            }
            System.out.print("#");
            if (tempRoot.left != null) {
                System.out.print(",");
            }
            tempRoot = tempRoot.left;
        }
        System.out.println("]");
        // end of print
    }
}