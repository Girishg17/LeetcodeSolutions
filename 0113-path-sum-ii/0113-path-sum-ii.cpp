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
    void solve(TreeNode * root,int targetSum,vector<vector<int>>&ans,vector<int>&temp,int sum ){
        if(root==NULL) return ;
        // if(root->val>targetSum)return false;
        if(sum+root->val==targetSum && root->left==NULL&&root->right==NULL){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        solve(root->left,targetSum,ans,temp,sum+root->val);
        solve(root->right,targetSum,ans,temp,sum+root->val);
        temp.pop_back();
        
        

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(root,targetSum,ans,temp,0);
        return ans;
    }
};