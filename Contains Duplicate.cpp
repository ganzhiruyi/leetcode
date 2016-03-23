class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 0;i < nums.size();++i)
            if(++mp[nums[i]] > 1) return true;
        return false;        
    }
};
// 版本二
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        hashmap<int,int>         
    }
};
