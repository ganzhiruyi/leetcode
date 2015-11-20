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
class Solution {
public:
	vector<string> ans;
	int nums[15],len;
	void dfs(int pos,int part,int part_num,string str_now,bool has_lead_zero = false){
		if(part_num > 255) return;
		if(part > 4) return;
		if(pos == len-1){
			if(part != 4) return;
			part_num = part_num*10+nums[pos];
			if(part_num > 255) return;
			str_now += (char)(nums[pos]+'0');
			ans.push_back(str_now);
			return;
		}
		str_now += (char)(nums[pos]+'0');
		if(part <= 3)
			dfs(pos+1,part+1,0,str_now+'.');
		part_num = part_num*10+nums[pos];
		has_lead_zero = part_num == 0;
		if(has_lead_zero) return; // 如果存在前导零，返回，注意这个trick，eg."010002"
		if(part_num <= 25)
			dfs(pos+1,part,part_num,str_now);
	}
    vector<string> restoreIpAddresses(string s) {
    	ans.clear();
    	len = s.length();
    	for(int i = 0;i < len;i++) nums[i] = s[i]-'0';
    	dfs(0,1,0,"");
    	return ans;
    }
};
int main(){
	string s;
	Solution sol;
	while(cin >> s){
		vector<string> v = sol.restoreIpAddresses(s);
		for(int i = 0;i < v.size();i++) cout << v[i] << endl;
	}
	return 0;
}