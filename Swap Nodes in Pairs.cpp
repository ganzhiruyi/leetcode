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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *pre,*cur,*post;
        cur = head,pre = NULL,post;
        bool flag = true;
        while(cur != NULL){
            post = cur->next;
            if(post != NULL){
                if(flag){
                    head = post;
                    flag = false;
                }
                cur->next = post->next;
                post->next = cur;
                if(pre != NULL) pre->next = post;
                pre = cur;
                cur = cur->next;
            }
            else break;
        }
        return head;
    }
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *p = head->next;
        head->next = swapPairs(p->next);
        p->next = head;
        return p;
    }
};
