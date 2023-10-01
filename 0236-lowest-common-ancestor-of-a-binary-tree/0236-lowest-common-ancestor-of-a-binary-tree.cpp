/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode * root,TreeNode * ele,vector<int>&arr){
        if(root==NULL)return false;
        if(root==ele){
            arr.push_back(ele->val);
            return true;
        }
        arr.push_back(root->val);
        if(solve(root->left,ele,arr))return true;
        if(solve(root->right,ele,arr))return true;
        arr.pop_back();
        return false;


        

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int>value1;
        vector<int>value2;
        solve(root,p,value1);
        solve(root,q,value2);

        int ans;
        int i=0,j=0;
        while(i<value1.size()&&j<value2.size()){
            if(value1[i]==value2[j]){
                ans=value1[i];
            }
            i++;
            j++;
        }
        TreeNode * temp=new TreeNode(ans);
        return temp;
       

        
    }
};