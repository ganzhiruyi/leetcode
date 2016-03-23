class Solution {
public:
    int getNodeCnt(ListNode *head){
        int cnt = 0;
        while(head){
            head = head->next;
            ++cnt;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = getNodeCnt(headA),lb = getNodeCnt(headB);
        if(la < lb){
            swap(headA,headB);
            swap(la,lb);
        }
        int diff = la-lb;
        while(diff--) headA = headA->next;
        while(headA){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
