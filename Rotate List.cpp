class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k) return head;
        ListNode *tmp,*r = head->next,*last = head;
        int n = 1;
        while(r){
            ++n;
            last = r;
            r = r->next;
        }
        k %= n;
        if(!k) return head;
        int cnt = 0;
        r = head;
        while(r){
            ++cnt;
            if(cnt == n-k){
                tmp = r->next;
                r->next = NULL;
                last->next = head;
                return tmp;
            }
            r = r->next;
        }
        return head;
    }
};
