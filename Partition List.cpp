#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100005;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> left,right;
        ListNode *p = head;
        while(p){
            if(p->val < x) left.push_back(p->val);
            else right.push_back(p->val);
            p = p->next;
        }
        p = head;
        for(int i = 0;i < left.size() && p;i++,p=p->next) p->val = left[i];
        for(int i = 0;i < right.size() && p;i++,p=p->next) p->val = right[i];
        return head;  
    }
};
void print_ListNode(ListNode *head){
    ListNode *p = head;
    while(p){
        printf("%d->", p->val);
        p = p->next;
    }
    printf("\n");
}
void del_ListNode(ListNode *head){
    if(head == NULL) return;
    if(head->next) del_ListNode(head->next);
    free(head);
}
int main(){
    int n,a;
    while(cin >> n){
        ListNode *head,*p;
        head = p = new ListNode(-1);
        for(int i = 0;i < n;i++){
            cin >> a;
            p->next = new ListNode(a);
            p = p->next;
        }
        Solution sol;
        int x;
        cin >> x;
        head = head->next;
        print_ListNode(head);
        head = sol.partition(head,x);
        print_ListNode(head);
        del_ListNode(head);
    }
    return 0;
}