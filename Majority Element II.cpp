class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int major1,major2,cnt1 = 0,cnt2 = 0;
        vector<int> ret;
        int n = nums.size();
        if(n == 0) return ret;
        major1 = nums[0];
        cnt1 = 1;
        for(int i = 1;i < n;++i){
            if(nums[i] == major1) ++cnt1;
            else if(nums[i] == major2) ++cnt2;
            else if(!cnt1 || !cnt2){
                if(!cnt1){
                    major1 = nums[i];
                    cnt1 = 1;
                }
                else{
                    major2 = nums[i];
                    cnt2 = 1;
                }
            }
            else{
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = 0,cnt2 = 0;
        for(int i = 0;i < n;++i){
            if(major1 == nums[i]) ++cnt1;
            else if(major2 == nums[i]) ++cnt2;
        }
        if(cnt1 > n/3) ret.push_back(major1);
        if(cnt2 > n/3) ret.push_back(major2);
        return ret;
    }
};
