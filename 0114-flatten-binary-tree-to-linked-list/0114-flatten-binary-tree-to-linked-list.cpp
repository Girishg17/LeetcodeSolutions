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
   void pushtoqueue(TreeNode * root,queue<TreeNode*>&q){
       if(root==NULL)return;
        q.push(root);
        pushtoqueue(root->left,q);
         pushtoqueue(root->right,q);

   }
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        queue<TreeNode*>q;
        TreeNode* temp1=root;
        pushtoqueue(temp1->left,q);
        TreeNode* temp=root->right;
        
        while(!q.empty()){
            
            root->right=q.front();
            root->left=NULL;
            root=root->right;
            q.pop();
        }
        root->right=temp;
        flatten(root->right);
        

        
    }
};