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
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int level=0;
        vector<int>temp;
        vector<vector<int>>ans;

        while(!q.empty()){
            TreeNode * node =q.front();
            q.pop();
            if(node && node->left) q.push(node->left);
            if(node && node->right)q.push(node->right);
            if(node)
            temp.push_back(node->val);
            if(q.front()==NULL){
                if(level++ % 2 !=0){
                    reverse(temp.begin(),temp.end());
                    
                }
                ans.push_back(temp);
                temp.clear();
                q.pop();
                if(!q.empty())q.push(NULL);
            }
      
        }
        return ans;
    }
};