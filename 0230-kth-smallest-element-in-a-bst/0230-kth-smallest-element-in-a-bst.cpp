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
    int ans;
    void solve(TreeNode * root,queue<int>&q){
      if(root==NULL)return;
      solve(root->left,q);
      q.push(root->val);
      solve(root->right,q);

       
    }
    int kthSmallest(TreeNode* root, int k) {
        queue<int>q;
       solve(root,q);
      
      while(--k)q.pop();
      return q.front();

        
    }
};