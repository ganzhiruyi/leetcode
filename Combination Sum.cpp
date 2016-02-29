class Solution {
public:
    /** 版本1: 88ms
    set<vector<int>> ans;
    bool dfs(int idx,vector<int>& candidates,vector<int> nums,int sum,int target){
        if(idx >= candidates.size() || sum + candidates[idx] > target)
            return false;
        if(sum + candidates[idx] == target){
            nums.push_back(candidates[idx]);
            ans.insert(nums);
            return true;
        }
        dfs(idx+1,candidates,nums,sum,target);
        nums.push_back(candidates[idx]);
        dfs(idx,candidates,nums,sum+candidates[idx],target);
        dfs(idx+1,candidates,nums,sum+candidates[idx],target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        ans.clear();
        vector<int> nums;
        dfs(0,candidates,nums,0,target);
        vector<vector<int>> ret;
        for(set<vector<int>>::iterator it = ans.begin(); it != ans.end();++it)
            ret.push_back(*it);
        return ret;
    }
    */
    /** 版本2:16ms, 几个优化：
    1. nums传引用
    2. 去掉sum，采取target减少的方式
    3. for循环跳过重复的数字，从而使结果中没有重复，不用set
    4. for循环candidates[i] <= target条件进行了一部分剪枝
    */
    vector<vector<int>> ans;
    void dfs(int idx,vector<int>& candidates,vector<int> &nums,int target){
        if(target == 0){
            ans.push_back(nums);
            return;
        }
        for(int i = idx;i < candidates.size() && candidates[i] <= target;++i){
            //去掉结果中的重复，因为一个数字可以取多次，所以重复的数字可以跳过
            if(i > 0 && candidates[i]==candidates[i-1]) continue;
            nums.push_back(candidates[i]);
            dfs(i,candidates,nums,target-candidates[i]);
            nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        ans.clear();
        vector<int> nums;
        dfs(0,candidates,nums,target);
        return ans;
    }
};
