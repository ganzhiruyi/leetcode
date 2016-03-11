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
