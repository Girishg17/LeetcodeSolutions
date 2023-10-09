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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *slow=head;
        ListNode *fast=head;
        while(n-- ){
            fast=fast->next;
           if(!fast)
        {
            head = head->next;
            delete slow;    // Since slow points to the first node
            return head;
        }
        }
        cout<<fast->val;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        if(slow->next==NULL)return NULL;
        slow->next=slow->next->next;
        

        return head;
       
    
    }
};