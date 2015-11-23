#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
 struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	int cur = 1;
    	ListNode *st,*tmp,*pre,*pre_st = NULL,*p = head;
    	while(p != NULL && cur < m){
    		++cur;
    		pre_st = p;
    		p = p->next;
    	}
    	st = pre = p;
    	p = p->next;
    	++cur;
    	while(p != NULL && cur <= n){
    		tmp = p->next;
    		p->next = pre;
 			pre = p;
    		p = tmp;
    		++cur;
    	}
    	if(pre_st) pre_st->next = pre;
    	else head = pre;
    	st->next = p;
    	return head;
    }
};
ListNode* build(){
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	for(int i = 2;i <= 10;i++){
		p->next = new ListNode(i);
		p = p->next;
	}
	return head;
}
void printList(ListNode* head){
	ListNode *p = head;
	while(p){
		printf("%d->", p->val);
		p = p->next;
	}
	printf("\n");
}
int main(){
	int n,m;
	Solution sol;
	while(cin >> n >> m){
		ListNode *head = build();
		printList(head);
		head = sol.reverseBetween(head,n,m);
		printList(head);
	}
	return 0;
}