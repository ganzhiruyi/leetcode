// 通用解法O(32n),空间复杂度O(32)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitCnt[32]; // 保存nums所有数中，每一位1出现的个数
        memset(bitCnt,0,sizeof(bitCnt));
        for(int i = 0;i < 32;++i){
            for(int j = 0;j < nums.size();++j){
                bitCnt[i] += (nums[j]>>i&1);
            }
        }
        int ans = 0;
        for(int i = 0;i < 32;++i)
            ans |= (bitCnt[i]%3<<i);// 如果i取k，这里就模k
        return ans;
    }
};
// 解法O(32n),空间复杂度O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0,bitCnt = 0; 
        for(int i = 0;i < 32;++i){
            bitCnt = 0;
            for(int j = 0;j < nums.size();++j){
                bitCnt += (nums[j]>>i&1);
            }
            ans += (bitCnt%3<<i);
        }
        return ans;
    }
};
// 解法O(n),空间复杂度O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0,two = 0,three = 0; // 分别记录每位出现1,2,3次数
        for(int i = 0;i < nums.size();++i){
            three = two & nums[i];
            two = two | one & nums[i];
            one = one | nums[i];
            one = one & ~three;
            two = two & ~three;
        }
        return one;
    }
};
