/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count=0;
    int solve1(TreeNode * root){
        if(root==NULL)return 0;
        return root->val+solve1(root->left)+solve1(root->right);
    }
     int solve(TreeNode * root){
         if(root==NULL)return 0;
         
         return 1+solve(root->left)+solve(root->right);
        
     }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL)return 0;
        
      int val=solve1(root);
      int n= solve(root);
      int temp=val/n;
      if(floor(temp)==root->val){
          count++;
      }
       averageOfSubtree(root->right);
      averageOfSubtree(root->left);
     
      return count;
    }
};