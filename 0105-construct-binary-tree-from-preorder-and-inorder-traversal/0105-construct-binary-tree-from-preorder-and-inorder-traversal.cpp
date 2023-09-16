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
  int preorindex=0;
  TreeNode * solve(vector<int>&pre,unordered_map<int,int>&mp,int i,int j){
   if(i>j)return NULL;
      int indexinorder=mp[pre[preorindex]];
      TreeNode* root =new TreeNode(pre[preorindex]);
      preorindex++;

    root->left=  solve(pre,mp,i, indexinorder-1);
     root->right= solve(pre,mp, indexinorder+1,j);
      return root;
  }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder,mp,0,inorder.size()-1);
    }
};