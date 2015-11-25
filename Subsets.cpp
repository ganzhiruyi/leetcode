#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > ans;
	int len;
	void dfs(vector<int> &nums,int pos,vector<int> v){
		if(pos == len){
			ans.push_back(v);
			return;
		}
		dfs(nums,pos+1,v);
		v.push_back(nums[pos]);
		dfs(nums,pos+1,v);
	}
    vector<vector<int> > subsets(vector<int>& nums) {
   		sort(nums.begin(),nums.end());
   		len = nums.size();
   		ans.clear();
   		vector<int> v;
   		dfs(nums,0,v);
   		return ans;
    }
};
int main(){
	Solution sol;
	int n;
	while(cin >> n){
		vector<int> v;
		int a;
		for(int i = 0;i < n;i++){
			cin >> a;
			v.push_back(a);
		}
		vector<vector<int> > ans = sol.subsets(v);
		for(int i = 0;i < ans.size();i++){
			cout << "[ ";
			for(int j = 0;j < ans[i].size();j++){
				cout << ans[i][j] << " ";
			}
			cout << " ]\n";
		}

	}
	return 0;
}