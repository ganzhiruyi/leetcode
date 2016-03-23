class Solution {
public:
    void print(ListNode *head){
        if(head == NULL) return;
        while(head){
            printf("%d->", head->val);
            head = head->next;
        }
        printf("\n");
    }
    ListNode *reverseList(ListNode *head){
        if(head == NULL) return NULL;
        ListNode *tmp,*pre = NULL;
        while(head){
            tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode *fast = head,*slow = head,*preSlow = NULL;
        while(fast && fast->next){
            fast = fast->next->next;
            preSlow = slow;
            slow = slow->next;
        }
        ListNode *head2;
        if(fast){ // 奇数个节点
            head2 = reverseList(slow->next);
            slow->next = NULL;
        }
        else{ // 偶数个节点
            head2 = reverseList(slow);
            preSlow->next = NULL;
        }
        fast = head,slow = head2;
        print(head);
        print(head2);
        while(slow){
            preSlow = fast->next;
            fast->next = slow;
            slow = slow->next;
            fast->next->next = preSlow;
            fast = preSlow;
        }
    }
};
