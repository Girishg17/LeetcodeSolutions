class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Define a min-heap (priority queue) to store pairs of (value, ListNode*)
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
       
      
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp) {
                pq.push({temp->val, temp});
                temp = temp->next;
            }
        }
        
       
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (!pq.empty()) {
            pair<int, ListNode*> topPair = pq.top();
            pq.pop();

            int val = topPair.first;
            ListNode* node = topPair.second;

            current->next = node;
            current = current->next;

            
        }

        return dummy->next; // Return the merged list
    }
};
