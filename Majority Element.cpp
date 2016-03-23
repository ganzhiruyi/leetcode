class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority,cnt = 0;
        for(int i = 0;i < nums.size();++i)
            if(cnt == 0){
                majority = nums[i];
                ++cnt;
            }
            else{
                if(majority == nums[i]) ++cnt;
                else --cnt;
                if(cnt > nums.size()/2) return majority;
            }
        return majority;
    }
};
