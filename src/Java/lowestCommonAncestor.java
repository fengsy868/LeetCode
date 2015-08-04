/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        int bigger,smaller;
        if(p.val >=q.val){
            bigger=p.val;
            smaller=q.val;
        }else{
            bigger=q.val;
            smaller=p.val;
        }
        if(bigger >= root.val && smaller <= root.val){
            return root;
        }else if(smaller > root.val){
            return lowestCommonAncestor(root.right,p,q);
        }else
            return lowestCommonAncestor(root.left,p,q);
    }
}