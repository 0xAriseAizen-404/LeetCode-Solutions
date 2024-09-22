/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
import java.util.*;

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) return ans;
        Queue<TreeNode> que = new LinkedList<>();
        que.add(root);
        boolean isZigzag = false;
        while (!que.isEmpty()) {
            int size = que.size();
            List<Integer> level = new ArrayList<>();
            for (int i = 0; i < size; ++i) {
                TreeNode temp = que.poll();
                level.add(temp.val);
                if (temp.left != null) que.add(temp.left);
                if (temp.right != null) que.add(temp.right);
            }
            if (isZigzag) Collections.reverse(level);
            isZigzag = !isZigzag;
            ans.add(level);
        }
        return ans;
    }
}
