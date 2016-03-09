// 利用merge sort来对链表进行排序
class Solution {
public:
    // 利用fast/slow前后指针，fast移动两步,slow移动一步，实现二分链表(奇数时长在左半部分)
    void split(ListNode *head,ListNode **left,ListNode **right){
        if(head == NULL || head->next == NULL){
            // 只有0/1个元素
            *left = head;
            *right = NULL;
            return;
        }
        ListNode *slow = head,*fast = head->next;
        // fast移动两个元素，slow移动一个元素
        while(fast){
            fast = fast->next;
            if(fast){
                fast = fast->next;
                slow = slow->next;
            }
        }
        *left = head,*right = slow->next,slow->next = NULL;
    }
    ListNode* merge(ListNode *a,ListNode *b){
        if(a == NULL) return b;
        if(b == NULL) return a;
        ListNode *ret = NULL;
        if(a->val <= b->val){
            ret = a;
            ret->next = merge(a->next,b);
        }
        else{
            ret = b;
            ret->next = merge(a,b->next);
        }
        return ret;        
    }
    ListNode* sortList(ListNode* head) {
        //只有0/1个元素
        if(head == NULL || head->next == NULL) return head;
        ListNode *left,*right;
        split(head,&left,&right); // 传入左右指针的引用(指针),内部修改
        left = sortList(left);
        right = sortList(right);
        return merge(left,right);
    }
};
