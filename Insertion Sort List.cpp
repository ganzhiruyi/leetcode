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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *st,*pre,*tail = head,*p = head->next;
        // tail:记录之前有序序列的尾
        // st:记录当前和之前有序序列哪个进行比较
        // pre：记录st的前一个指针
        // p:记录当前的指针
        // nextp:记录p的下一个指针
        while(p){
            ListNode *nextp = p->next; 
            bool find = false; // 表示是否在之前的有序序列中找到插入点
            for(st=head,pre=NULL;st != p;st=st->next){
                if(st->val > p->val){
                    find = true;
                    if(pre){
                        p->next = pre->next;
                        pre->next = p;
                        tail->next = nextp;
                    }
                    else{// p比head还要小，更新head
                        p->next = head;
                        head = p;
                        tail->next = nextp;
                    }
                    break;
                }
                pre = st;
            }
            if(!find) tail = p; // 没找到，p就是新的有序序列的尾
            p = nextp;
        }
        return head;
    }
};
