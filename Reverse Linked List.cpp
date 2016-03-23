class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *tmp = head,pre = NULL;
        while(head){
            tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
};
