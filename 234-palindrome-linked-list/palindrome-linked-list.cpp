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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)return true;
        ListNode * slow=head;
        ListNode * fast=head;
        stack<ListNode*>st;
        while(fast!=NULL && fast->next!=NULL){
            st.push(slow);    
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast && fast->next==NULL)slow=slow->next;
        while(slow!=NULL && !st.empty()){
            if(slow->val!=st.top()->val)return false;
            st.pop();
            slow=slow->next;
        }
        if(!st.empty() || slow!=NULL)return false;
        return true;


        
    }
};