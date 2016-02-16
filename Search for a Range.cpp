class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int first = lower_bound(nums.begin(), nums.end(),target)-nums.begin();
        if(first == nums.size() || nums[first] != target){
            v.push_back(-1),v.push_back(-1);
            return v;
        }
        int last = upper_bound(nums.begin(), nums.end(),target)-nums.begin();
        v.push_back(first),v.push_back(last-1);
        return v;
    }
};
