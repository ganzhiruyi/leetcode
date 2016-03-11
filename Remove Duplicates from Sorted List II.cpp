class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode *tmp,*p = head->next,*pre = head,*ppre = NULL;
        while(p){
            bool find = false;
            while(p && p->val == pre->val){
                find = true;
                tmp = p;
                pre->next = p->next;
                p = p->next;
                free(tmp);
            }
            if(find){
                free(pre);
                if(ppre == NULL){
                    head = p;
                    pre = p;
                    if(p) p = p->next;
                    ppre = NULL;
                }
                else{
                    ppre->next = p;
                    pre = p;
                    if(p) p = p->next;
                }
            }
            else{
                ppre = pre;
                pre = p;
                if(p) p = p->next; 
            }
        }
        return head;
    }
};
