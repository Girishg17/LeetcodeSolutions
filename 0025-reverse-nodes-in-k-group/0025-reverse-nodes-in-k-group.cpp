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
ListNode* solve(ListNode *head,int &size,int &cursize){
    if(size>cursize)return head;
    if(head==NULL)return head;
    ListNode *curr=head,*prev=NULL,*follow=head;
    int x=0;
    while(curr!=NULL&& x<size){
        follow=follow->next;
        curr->next=prev;
        prev=curr;
        curr=follow;
        x++;
    }
    cursize=cursize-x;
    head->next=solve(follow,size,cursize);
    return prev;
}
int size(ListNode * head){
   
    int k=0;
    while(head){
        k++;
        head=head->next;

    }
    return k;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
       int n=size(head);
      return solve(head,k,n);
    }
};