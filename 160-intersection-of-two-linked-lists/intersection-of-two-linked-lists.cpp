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
    ListNode* solve(ListNode* large,int size1,int size2){
            while(size1!=size2){
                large=large->next;
                size1--;
            }
            return large;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * list1=  headA;
        ListNode * list2 = headB;
        int size1=0;
        int size2=0;
        while(list1){
            list1=list1->next;
            size1++;
        }
         while(list2){
            list2=list2->next;
            size2++;
        }
        if(size1>size2){
           headA= solve(headA,size1,size2);
        }
        else{
           headB= solve(headB,size2,size1);
        }
        while(headA && headB && headA != headB){
            cout<<headA->val<<","<<headB->val;
            headA=headA->next;
            headB=headB->next;
        }
        if(headA==headB)return headA;

       return NULL;
        
    }
};