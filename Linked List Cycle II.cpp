class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *pre = head,*fast = head,*slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        if(!fast || !fast->next) return NULL;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;    
    }
};
