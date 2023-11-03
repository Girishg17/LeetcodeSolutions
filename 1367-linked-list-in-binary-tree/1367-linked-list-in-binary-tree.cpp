/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
   void find(vector<TreeNode*>&arr,TreeNode* root,int val){
       if(root==NULL)return;
       if(root->val==val)arr.push_back(root);
       find(arr,root->left,val);
       find(arr,root->right,val);

   }
   bool solve(TreeNode * root,ListNode * head){
      
       if(head==NULL)return true;
        if(root==NULL)return false;
       bool flag=false;
       if(head->val==root->val){
          return solve(root->left,head->next)
           || solve(root->right,head->next);
       }
       return false;
   }
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode*>arr;
        find(arr,root,head->val);
        for(int i=0;i<arr.size();i++){
            ListNode* temp=head;
            if(solve(arr[i],temp))return true;
        }
        return false;
        
    }
};