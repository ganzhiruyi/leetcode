class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *odd = head,*even = head->next,*tmp = even,*p = head->next->next;
        bool isOddNode = true;
        while(p){
            if(isOddNode) odd->next = p,odd = p;
            else even->next = p,even = p;
            isOddNode = !isOddNode; 
            p = p->next;
        }
        even->next = NULL; // 这句一定要加
        odd->next = tmp;
        return head;
    }
};
