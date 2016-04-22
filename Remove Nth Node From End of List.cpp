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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !n) return head;
        ListNode *fast = head,*slow = head,*pre = NULL;
        while(--n)
            fast = fast->next;
        while(fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(slow == head)
            head = head->next;
        else pre->next = slow->next;
        delete slow;
        return head;
    }
};
