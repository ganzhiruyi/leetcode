#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	int len;
	map<int,int> cnt_mp;
	vector<vector<int> > ans;
	void dfs(vector<int> &nums,int pos,vector<int> v){
		if(pos == len){
			ans.push_back(v);
			return;
		}
		int num = nums[pos];
		int cnt = cnt_mp[num];
		int next_pos = pos + cnt;
		dfs(nums,next_pos,v);
		for(int i = 1;i <= cnt;i++){
			v.push_back(num);
			dfs(nums,next_pos,v);
		}
	}
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
   		sort(nums.begin(),nums.end());
   		for(int i = 0;i < nums.size();i++)
   			if(cnt_mp.find(nums[i]) != cnt_mp.end()) ++cnt_mp[nums[i]];
   			else cnt_mp[nums[i]] = 1;
   		len = nums.size();
   		ans.clear();
   		vector<int> v;
   		dfs(nums,0,v);
   		return ans;
    }
};
int main(){
	int n;
	while(cin >> n){
		Solution sol;
		vector<int> v;
		int a;
		for(int i = 0;i < n;i++){
			cin >> a;
			v.push_back(a);
		}
		vector<vector<int> > ans = sol.subsetsWithDup(v);
		for(int i = 0;i < ans.size();i++){
			cout << "[ ";
			for(int j = 0;j < ans[i].size();j++){
				cout << ans[i][j] << " ";
			}
			cout << " ]\n";
		}
		cout << "*******************" << endl;
	}
	return 0;
}