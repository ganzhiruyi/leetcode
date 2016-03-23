class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL || node->next == NULL) return;
        node->val = node->next->val;
        ListNode *tmp = node->next;
        node->next = node->next->next;
        free(tmp);
    }
};
