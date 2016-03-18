class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *slow = head,*fast = head;
        while(fast){
            fast = fast->next;
            if(fast){
                fast = fast->next;
                slow = slow->next;
                if(slow == fast) return true;
            }
        }
        return false;        
    }
};
