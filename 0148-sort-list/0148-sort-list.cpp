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
class Solution {
public:
    ListNode * mergelist(ListNode * l1,ListNode * l2){
        ListNode * curr=new ListNode (0);
        ListNode * temp=curr;
        
        while(l1!=NULL &&l2!=NULL){
            if(l1->val<=l2->val){
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(l1)
            curr->next=l1;
            
            
        
if(l2)
      curr->next=l2;
           
        
        return temp->next;

    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;

        ListNode * fast=head;
        ListNode* slow=head;
        ListNode* tempT=NULL;
        while(fast!=NULL && fast->next!=NULL){
            tempT=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
       
        tempT->next=NULL;
        
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        return mergelist(l1,l2);

        
    }
};