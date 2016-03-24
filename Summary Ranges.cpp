class Solution {
public:
    string int2str(int x){
        stringstream ss;
        string s;
        ss << x;
        ss >> s;
        return s;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        int st = 0;
        vector<string> vs;
        if(!nums.size()) return vs;
        if(!nums.size() == 1){
            vs.push_back(int2str(nums[0]));
            return vs;
        }
        for(int i = 1;i < nums.size();++i)
            if(nums[i] != nums[i-1]+1){
                if(st == i-1) vs.push_back(int2str(nums[st]));
                else vs.push_back(int2str(nums[st])+"->"+int2str(nums[i-1]));
                st = i;
            }
        if(st == nums.size()-1) vs.push_back(int2str(nums[st]));
        else vs.push_back(int2str(nums[st])+"->"+int2str(nums[nums.size()-1]));
        return vs;
    }
};
