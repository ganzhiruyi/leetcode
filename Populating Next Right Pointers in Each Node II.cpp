#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 205
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
struct TreeLinkNode {
	int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
vector<TreeLinkNode*> tree;
class Solution {
public:
   queue<TreeLinkNode*> q;
   void connect(TreeLinkNode *root) {
   	if(root == NULL) return;
   	while(!q.empty()) q.pop();
   	q.push(root);
   	int cnt = 1;
   	TreeLinkNode *ft,*pre;
   	while(!q.empty()){
   		pre = NULL;
         int tmpCnt = 0;
   		for(int i = 0;i < cnt;i++){
   			ft = q.front();
   			q.pop();
   			if(pre) pre->next = ft;
   			if(ft->left) q.push(ft->left),++tmpCnt;
   			if(ft->right) q.push(ft->right),++tmpCnt;
   			pre = ft;
   		}
         cnt = tmpCnt;
   	}
   }
};
int D;
TreeLinkNode* build(int depth,int &val){
   if(depth == D) return NULL;
   TreeLinkNode *rt = new TreeLinkNode(++val);
   rt->left = build(depth+1,val);
   rt->right = build(depth+1,val);
   return rt;
}
void print_tree(TreeLinkNode *rt){
   if(rt == NULL) return;
   queue<TreeLinkNode*> q;
   q.push(rt);
   int cntUp = 1;
   TreeLinkNode *f;
   while(!q.empty()){
      for(int i = 0;i < cntUp;i++){
         f = q.front();
         printf("%d ", f->val);
         q.pop();
         if(f->left) q.push(f->left);
         if(f->right) q.push(f->right);
      }
      printf("\n");
      cntUp <<= 1;
   }
}
void print_connect(TreeLinkNode *rt){
   if(rt == NULL) return;
   TreeLinkNode *st = rt;
   while(st){
      TreeLinkNode *p = st;
      while(p){
         printf("%d ", p->val);
         p = p->next;
      }
      printf("\n");
      st = st->left;
   }
}
void del_tree(TreeLinkNode *rt){
   if(!rt) return;
   if(rt->left) del_tree(rt->left);
   if(rt->right) del_tree(rt->right);
   free(rt);
}
int main(){
   while(cin >> D){
      int val = 0;
      TreeLinkNode *rt = build(0,val);
      print_tree(rt);
      printf("****************\n");
      Solution so;
      so.connect(rt);
      print_connect(rt);
      del_tree(rt);
   }
   return 0; 
}