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
   bool find(ListNode * head,TreeNode * root){
       if(root==NULL)return false;
       if(root->val==head->val){
          if( solve(root,head))return true;
       }
     return  find(head,root->left)
        || find(head,root->right);

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
        return find(head,root);
        
    }
};