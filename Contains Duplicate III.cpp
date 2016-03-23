class Solution {
public:
    typedef pair<int,int> pii;
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pii> p;
        for(int i = 0;i < nums.size();++i) p.push_back(make_pair(nums[i],i));
        sort(p.begin(), p.end());
        for(int i = 0;i < nums.size();++i){
            int tmp = p[i].first+t;
            for(int j = i+1;j < nums.size() && p[j].first <= tmp;++j){
                if(abs(p[j].second-p[i].second) <= k) return true;
            }
        }
        return false;
    }
};
