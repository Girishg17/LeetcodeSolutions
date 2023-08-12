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
    void inorder(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&map,TreeNode*parent){
        if(root==NULL)return;
        inorder(root->left,map,root);
        map[root]=parent;
        inorder(root->right,map,root);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
     unordered_map<TreeNode*,TreeNode*>map;
      inorder(root,map,NULL);
      queue<TreeNode*>q;
      unordered_map<TreeNode*,int>vis;
      q.push(target);
      vis[target] = 1;
      while(k--){
         int size=q.size();
         while(size--){
             TreeNode* front=q.front();
             q.pop();
            if(front->left && vis.find(front->left)==vis.end()){
                q.push(front->left);
                vis[front->left]=1;
            }
            if(front->right&&vis.find(front->right)==vis.end()){
                q.push(front->right);
                vis[front->right]=1;
            }
            TreeNode* parent = map[front];
            if(parent&&vis.find(parent)==vis.end()){
                q.push(parent);
                vis[parent]=1;
            }

         }


      }
      vector<int>ans;

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();

        }
        return ans;
    }
};