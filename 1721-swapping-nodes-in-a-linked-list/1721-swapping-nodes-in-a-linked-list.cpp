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
int solve(ListNode* head){
    int s=0;
    while(head){
        s++;
        head=head->next;
    }
    return s;
}
    ListNode* swapNodes(ListNode* head, int k) {
      
        int x=0;
    
        ListNode * temp=head;
         ListNode * slow=head;
        ListNode* ktfromstart=NULL;
        ListNode * kthfromedn=NULL;
        
      
        while(x<k-1){
            x++;
         
            temp=temp->next;
        }
        ktfromstart=temp;
       
       
        while(temp->next){
           
            temp=temp->next;
            slow=slow->next;
           
        }
    
      
      swap(ktfromstart->val,slow->val);

        return head;
        
    }
};