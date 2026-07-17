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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         if(root==NULL)return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        bool goRight=true;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int totalIndex=size;
            vector<int>tempAns(totalIndex);
            int i=0;
            while(size--){
                TreeNode * node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                if(goRight){
                    tempAns[i]=node->val;
                   
                }
                else{
                    tempAns[totalIndex-i-1]=node->val;
                }
                i++;
            }
            ans.push_back(tempAns);
            if(goRight){
                goRight=false;
            }
            else{
                goRight=true;
            }

        }
        return ans;


    
    }
};