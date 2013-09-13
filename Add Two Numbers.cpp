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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pre = 0;
        ListNode *st = new ListNode(0);
        ListNode *head;
        head = st;
        for(;l1 != NULL || l2 != NULL;){
            if(l1 != NULL){
                if(l2 != NULL){
                    int val = (l1->val+l2->val+pre)%10;
                    pre = (l1->val+l2->val+pre)/10;
                    ListNode *cur = new ListNode(val);
                    st->next = cur;
                    st = cur;
                    l2 = l2->next;
                }
                else{
                    int val = (l1->val+pre)%10;
                    pre = (l1->val+pre)/10;
                    ListNode *cur = new ListNode(val);
                    st->next = cur;
                    st = cur;
                }
                l1 = l1->next;
            }
            else{
                if(l2 != NULL){
                    int val = (l2->val+pre)%10;
                    pre = (l2->val+pre)/10;
                    ListNode *cur = new ListNode(val);
                    st->next = cur;
                    st = cur;
                    l2 = l2->next;
                }
            }
        }
        if(pre != 0){
            ListNode *cur = new ListNode(pre);
            st->next=cur;
        }
        return head->next;
    }
};
