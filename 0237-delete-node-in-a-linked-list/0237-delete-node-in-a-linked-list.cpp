/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * front=node->next;
        ListNode * prev=NULL;
        while(front){
            int temp=node->val;
             node->val=front->val;
            front->val=temp;
            prev=node;
           
            node=node->next;
            front=front->next;
        }
        prev->next=NULL;

        
    }
};