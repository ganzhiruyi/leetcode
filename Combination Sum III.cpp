class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int k,int num,int target,vector<int> nums){
        /** k表示当前还剩多少元素,num表示上一次选择的数,
        target表示当前要求的和是多少,nums表示当前已经记录的数
        **/
        if(k == 0){
            if(target == 0)
                ans.push_back(nums);
            return;
        }
        for(int i = num+1;i <= 9;++i){
            vector<int> t = nums;
            t.push_back(i);
            dfs(k-1,i,target-i,t);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        dfs(k,0,n,vector<int>());
        return ans;
    }
};
