// 版本一 O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size());
        for(int i = 0;i < nums.size();++i){
            lis[i] = 1;
            for(int j = 0;j < i;++j){
                if(nums[j]<nums[i])
                    lis[i] = max(lis[i],lis[j]+1);
            }
        }
        int ret = 0;
        for(int i = 0;i < nums.size();++i)
            ret = max(ret,lis[i]);
        return ret;
    }
};
// 版本二 O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        /**
        tailTable[i]表示第i个(长度为i+1)IS的末尾数字,
        tailTableCnt表示当前有了多少个IS串，
        如果要打印LIS，直接把[0,tailTableCnt)的tailTable[i]打印出来即可，
        这个顺序也是最短长度中字母顺序最小的
        **/
        int *tailTable = new int[nums.size()]; 
        int tailTableCnt = 1, n = nums.size();
        tailTable[0] = nums[0];
        for(int i = 1;i < n;++i){
            if(nums[i] < tailTable[0])
                tailTable[0] = nums[i];
            else if(nums[i] > tailTable[tailTableCnt-1])
                tailTable[tailTableCnt++] = nums[i];
            else{
                int idx = lower_bound(tailTable,tailTable+tailTableCnt,nums[i])-tailTable;
                tailTable[idx] = nums[i];
            }
        }
        delete[] tailTable;
        return tailTableCnt;
    }
};
