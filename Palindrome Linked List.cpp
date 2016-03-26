class Solution {
public:
    ListNode* reverseList(ListNode *head){
        ListNode *tmp,*pre = NULL;
        while(head){
            tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    } 
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *fast=head,*slow=head,*preSlow=NULL;
        while(fast && fast->next){
            fast = fast->next->next;
            preSlow = slow;
            slow = slow->next;
        }
        if(fast){ // 奇数个节点
            ListNode *newHead = reverseList(slow->next);
            slow = head, fast = newHead;
            while(slow != preSlow->next){
                if(slow->val != fast->val){
                    // 把原来的链表逆转回来
                    preSlow->next->next = reverseList(newHead); 
                    return false;
                }
                slow = slow->next,fast = fast->next;
            }
            preSlow->next->next = reverseList(newHead);
            return true;
        }
        else{ // 偶数个节点
            ListNode *newHead = reverseList(slow);
            slow = head,fast = newHead;
            while(slow != preSlow->next){
                if(slow->val != fast->val){
                    preSlow->next = reverseList(newHead);
                    return false;
                }
                slow = slow->next,fast = fast->next;
            }
            preSlow->next = reverseList(newHead);
            return true;
        }
    }
};
