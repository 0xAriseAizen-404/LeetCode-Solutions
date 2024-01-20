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
class Solution
{
    int moves= 0;//Stores the minimum number of moves to make the tree coins to be balanced 
    public int distributeCoins(TreeNode root)
    {
        helper(root);//helps us in finding the minimum number of moves to be balanced 
        return moves;//returning
    }
    public int helper(TreeNode root)
    {//Postorder traversal, we know about the child situation first and then the parent 
        if(root == null)//base case when we hit the null node, we return 0 as no coins is required null node is already balanced 
           return 0;

        int coinsLeft= helper(root.left);//recursing down the left subtree and knowing about left child, what is the status about coins 
	    int coinsRight= helper(root.right);//recursing down the right subtree and knowing about right child, what is the status about coins 
       
        int coins= coinsLeft + coinsRight;//adding the information recived from left and right child //total coins collected from childrens
        
        //root node situation 
        if(root.val == 0) //root node cannot contribute, but needs coin from its parent 
          coins-= 1;//current node need one coin from parent
      
        else if(root.val == 1)//root node cannot contribute, at par
          coins+= 0;
      
        else //root node can contribute to its parent
          coins+= root.val- 1;//excess coin are been transfered to the parent 
    
        moves+= Math.abs(coins);//no matter how much coin is required by the node to get balanced or the number of coins to be transfered to the parent//we only count the steps, so we take the magnitude
      
        return coins;//coin tell the present sceneario to parent
      //case 1 : coins < 0 (need coin) //case 2 : coins > 0 (excess coin) //case 3 : coins == 0(No extra coin let, at par) 
    }
}//Please do Upvote, it helps a lot