#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	int len;
  /* 分析dfs可知，记忆化搜索可以转化为dp问题,这里:
    1.f[i][0]表示到第i个位置为止，且将位置i当做个位数字解码能获得的方法数;
    2.f[i][1]表示到第i个位置为止，且将位置i当做两位数的第一个数字解码能获得的方法数;
    3.f[i][0]表示到第i个位置为止，且将位置i当做两位数的第二个数字解码能获得的方法数;
  */
  int numDecodings(string s) {
		len = s.length();
		if(len == 0) return 0;
		int f[len][3];
		memset(f,0,sizeof(f));
		f[0][0] = s[0] > '0';
		f[0][1] = s[0] == '1' || s[0] == '2'; 
		for(int i = 1;i < len;i++){
			if(s[i] == '0'){
				f[i][2] = f[i-1][1];
			}
			else if(s[i]=='1' || s[i]=='2'){
				f[i][0] = f[i-1][0]+f[i-1][2];
				f[i][1] = f[i-1][0]+f[i-1][2];
				f[i][2] = f[i-1][1];
			}
			else{
				f[i][0] = f[i-1][0]+f[i-1][2];
				if(s[i-1] == '1')
					f[i][2] += f[i-1][1];
				else if(s[i-1] == '2')
					f[i][2] += ('0'<s[i] && s[i]<'7' ? f[i-1][1] : 0);
			}

		}
		return f[len-1][0]+f[len-1][2];
  }
};
class Solution1 {
public:
	int ans,len;
	vector<int> nums;
  /* dfs方法超时，因为对于当前位的数字大于2的位置，一定是作为一个单独的字符解码，
    那么从开始到这个点位置的方法数是定下来的，然而dfs每次会重复计算这些值，因此
    可以加上记忆化搜索可以过，这里没有尝试这种方法
  */
	void dfs(int pos,int pre){
		if(pos == len-1){
			if(!pre) ans += (nums[pos] > 0);
			else if(pre == 1) ++ans;
			else if(pre == 2) ans += (nums[pos]<=6);
			return;
		}
		if(!pre){
			if(nums[pos] > 0) dfs(pos+1,0);
			if(0 < nums[pos] && nums[pos] <= 2) dfs(pos+1,nums[pos]);
		}
		else if(pre == 1) dfs(pos+1,0);
		else if(pre == 2 && nums[pos] <= 6) dfs(pos+1,0);
	}
    int numDecodings(string s) {
  		len = s.length();
  		if(len == 0) return 0;
  		ans = 0;
  		nums.clear();
  		for(int i = 0;i < len;i++)
  			nums.push_back(s[i]-'0');
  		dfs(0,0);
  		return ans;
    }
};
int main(){
	string s;
	Solution sol;
	Solution1 sol1;
	while(cin >> s){
		cout << sol1.numDecodings(s) << endl;
		cout << sol.numDecodings(s) << endl;
	}
	return 0;
}