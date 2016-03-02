/* 版本1: TLE
f[i]表示到达第i个位置需要的最少步数，直接枚举每个位置能到达的位置，递推
复杂度O(n^2)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n,n);
        f[0] = 0;
        for(int i = 0;i < n;++i){
            for(int j = 1;j <= nums[i] && i+j < n;++j){
                f[i+j] = min(f[i+j],f[i]+1);
            }
        }
        return f[n-1];
    }
};
/* 版本2：16ms
注意到版本1中对于i能到达的位置p，j：[i+1,n)就算也能到达这个位置p,
一定有f[i] < f[j]，所以可以省略掉这部分，即对于每个位置i，只更新[start,end]范围内的f值，
start表示它之前的位置i-1能到达的最远位置，end表示位置i自己能到达的最远位置，
这样看来平均的复杂度为O(n)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n,n);
        f[0] = 0;
        int start = 0;
        for(int i = 0;i < n;++i){
            int end = min(i+nums[i],n-1);
            for(int j = start;j <= end;++j){
                f[j] = min(f[j],f[i]+1);
            }
            start = end;
        }
        return f[n-1];
    }
};
