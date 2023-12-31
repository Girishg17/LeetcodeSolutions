/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* deleteDuplicates(ListNode *head)
        {
            map<int,int>mp;
            ListNode*temp=head;
            while(temp){
                mp[temp->val]++;
                temp=temp->next;
            }
            ListNode* dummy=new ListNode(0);
            ListNode * prev=dummy;
            for(auto it:mp){
                if(it.second==1){
                    ListNode*newnode=new ListNode(it.first);
                    prev->next=newnode;
                    prev=prev->next;
                }



            }
            return dummy->next;
        }
};
