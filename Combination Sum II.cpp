class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int idx,vector<int>& candidates,vector<int>& nums,int target){
        if(target == 0){
            ans.push_back(nums);
            return;
        }
        for(int i = idx;i < candidates.size() && candidates[i] <= target;++i){
            // 子问题中重复的数字不选
            if(i > idx && candidates[i]==candidates[i-1]) continue;
            nums.push_back(candidates[i]);
            dfs(i+1,candidates,nums,target-candidates[i]);
            nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        ans.clear();
        vector<int> nums;
        dfs(0,candidates,nums,target);
        return ans;
    }
};
