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
   void solve(unordered_map<int,int>&mp,TreeNode * root){
       if(root==NULL)return;
       mp[root->val]++;
       solve(mp,root->left);
       solve(mp,root->right);

   }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        solve(mp,root);
        vector<int>ans;
        int maxvalue=INT_MIN;
        for(auto &it:mp){
            if(it.second>maxvalue){
                ans.clear();
                maxvalue=it.second;
                ans.push_back(it.first);

            }
            else if(it.second==maxvalue){
                ans.push_back(it.first);
            }


        }
        return ans;
        
    }
};