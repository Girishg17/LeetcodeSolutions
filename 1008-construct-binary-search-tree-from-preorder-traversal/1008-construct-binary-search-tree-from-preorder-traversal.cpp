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
  TreeNode * recursive(vector<int>&pre,int ub,int &i){
      if(i>=pre.size()||pre[i]>ub)return NULL;
      TreeNode* root=new TreeNode(pre[i]);
      i++;
      root->left=recursive(pre,root->val,i);
      root->right=recursive(pre,ub,i);
      return root;
    

      
  }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return recursive(preorder,INT_MAX,i);
        
    }
};