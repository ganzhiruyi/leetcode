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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL) return NULL;;
        bool has = false;
        ListNode* next = find(head,has,k);
        ListNode *after,*tmp,*p = head,*pre = NULL;
        if(has){
            //cout << "next: " << next << endl;
            after = reverseKGroup(next,k);
            while(k--){
                tmp = p->next;
                p->next = pre;
                pre = p;
                p = tmp;
            }
            head->next = after;
            return pre;
        }
        else return head;
    }
    ListNode* find(ListNode *head, bool &has, int k){
        ListNode *p = head;
        while(p && k){
            p = p->next;
            k--;
        }
        if(k){
            has = false;
            return NULL;
        }
        has = true;
        return p;
    }
};
