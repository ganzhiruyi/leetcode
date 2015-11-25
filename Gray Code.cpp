#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> ans;
    int len;
    // 把整个排列想成一棵完全二叉树,深度即为len，
    // 0边连接左儿子，1边连接右儿子.
    // lr = true表示当前位置是先遍历放0的情况,再遍历放1的情况；
    // lr = false 相反
    void dfs(int pos,int num,bool lr){
    	if(pos == len){
    		ans.push_back(num);
    		return;
    	}
    	if(lr){
    		dfs(pos+1,num<<1,true);
    		dfs(pos+1,num<<1|1,false);
    	}
    	else{
    		dfs(pos+1,num<<1|1,true);
    		dfs(pos+1,num<<1,false);
    	}
    }
    vector<int> grayCode(int n) {
 		ans.clear();
 		len = n;
 		dfs(0,0,true);
 		return ans;
    }
};
int main(){
	int n;
	Solution sol;
	while(cin >> n){
		vector<int> v = sol.grayCode(n);
		for(int i = 0;i < v.size();i++)
			cout << v[i] << " ";
		cout << endl; 
	}
	return 0;
}