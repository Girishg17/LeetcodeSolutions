/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slowRunner = head;
    struct ListNode *fastRunner = head;
    
    while(fastRunner && fastRunner->next)
    {
        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next->next;
        if(slowRunner == fastRunner)
            return 1;
    }
    return 0;
}