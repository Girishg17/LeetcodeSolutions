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
    void reorderList(ListNode* head) {

        stack<ListNode*> st;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow->next;
        slow->next = NULL;
        while (temp) {
            st.push(temp);
            temp = temp->next;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (!st.empty()) {
            ListNode* node = st.top();
            st.pop();
            prev->next = node;
            node->next = curr;
            prev = curr;
            curr = curr->next;
        }
    }
};