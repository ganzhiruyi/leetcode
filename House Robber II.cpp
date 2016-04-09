#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // 三个特判，去除边界条件
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        /**
        f[i][0]表示不取第一个，以第i个为结尾能取到的最大值
        f[i][1]表示取第一个，以第i个为结尾能取到的最大值
        **/
        int f[n+1][2];
        f[0][1] = nums[0],f[0][0] = 0;
        for(int i = 1;i < n-1;++i){
            f[i][0] = f[i-1][0],f[i][1] = f[i-1][1];
            // 如果i就是第二个，那么f[i][0] ！= f[i-1][0]，而是nums[i]
            if(i == 1) f[i][0] = nums[i];
            if(i >= 2){
                f[i][0] = max(f[i][0],f[i-2][0]+nums[i]);
                f[i][1] = max(f[i][1],f[i-2][1]+nums[i]);
            }
        }
        f[n-1][0] = f[n-2][0];
        f[n-1][0] = max(f[n-1][0],f[n-3][0]+nums[n-1]);
        f[n-1][1] = f[n-2][1]; 
        int ans = 0;
        for(int i = 0;i < n;++i)
            ans = max(ans,max(f[i][0],f[i][1]));
        return ans;
    }
};
int main(){
    int n,k = 0;
    cin >> n;
    vector<int> a(n);
    while(k < n){
        cin >> a[k++];
    }
    Solution sol;
    sol.rob(a);
    return 0;
}
