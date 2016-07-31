class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0,j = 0,l1 = nums1.size(),l2 = nums2.size();
        vector<int> ret;
        while(i < l1 && j < l2){
            if(nums1[i] == nums2[j]){
                ret.push_back(nums1[i]);
                ++i,++j;
                while(i < l1 && nums1[i]==nums1[i-1]) ++i;
                while(j < l2 && nums2[j]==nums2[j-1]) ++j;
            }
            else if(nums1[i] < nums2[j]) ++i;
            else ++j;
        }
        return ret;
    }
};
