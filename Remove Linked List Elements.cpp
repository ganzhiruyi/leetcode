class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = head,*pre = NULL;
        while(p){
            if(p->val == val){
                if(p == head){
                    head = p->next;
                    pre = NULL;
                    free(p);
                    p = head;
                }
                else{
                    pre->next = p->next;
                    free(p);
                    p = pre->next;
                }
            }
            else{
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};
