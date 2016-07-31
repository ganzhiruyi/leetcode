class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *tmp,*p = head->next,*pre = head;
        while(p){
            if(p->val == pre->val){
                tmp = p;
                pre->next = p->next;
                p = p->next;
                free(tmp);
            }
            else{
                pre = p;
                p = p->next;
            }
        }
        return head;        
    }
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *st = head,*p = head->next;
        while(p && p->val == st->val){
            free(st);
            st = p;
            p = p->next;
        }
        st->next = deleteDuplicates(p);
        return st;
    }
};
