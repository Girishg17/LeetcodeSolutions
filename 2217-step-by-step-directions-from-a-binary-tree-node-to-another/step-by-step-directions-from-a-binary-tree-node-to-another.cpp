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
    string finalDest="";
    string finalStart="";
    void solve(TreeNode * root,int dest,string &s,int start){
        if(root==NULL)return;
        if(root->val==start){
            finalStart=s;
        }
        if(root->val==dest){
            finalDest=s;
            
            }
        s.push_back('L');
        solve(root->left,dest,s,start);
        s.pop_back();
        s.push_back('R');
        solve(root->right,dest,s,start);
        s.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        
        string temp="";
        solve(root,destValue,temp,startValue);
        
        int i=0,j=0;
        int m=finalStart.size(),n=finalDest.size();

        while(finalStart!= "" &&  finalDest!="" && finalStart[0]==finalDest[0]){
            finalStart.erase(0,1);
            finalDest.erase(0,1);
        }
        string ex="";
        int k=0;
        while(k<finalStart.size()){
            ex.push_back('U');
            k++;
        }
        return ex+finalDest;
    }
};