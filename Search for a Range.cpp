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
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        int mid,l = 0,r = nums.size()-1;
        while(l < r){
            mid = l+(r-l>>1);
            if(nums[mid] >= target) r = mid;
            else l = mid+1;
        }
        if(r == -1 || nums[r] != target)
            return {-1,-1};
        ret.push_back(r);
        l = 0,r = nums.size();
        while(l < r){
            mid = l+(r-l>>1);
            if(nums[mid] > target) r = mid;
            else l = mid+1;
        }
        ret.push_back(r-1);
        return ret;
    }
};
