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
    TreeNode * solve(ListNode * &root,int index,int size){
        if(index>=size)return NULL;
        TreeNode* temp=new TreeNode();
        temp->left=solve(root,2*index+1,size);
        temp->val=root->val;
        root=root->next;
        temp->right=solve(root,2*index+2,size);
        return temp;



    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode * temp=head;
        int size=0;
        while(temp){
            size++;
            temp=temp->next;

        }

        return solve(head,0,size);
        
    }
};