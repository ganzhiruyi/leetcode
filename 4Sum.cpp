#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        int l,r,n = nums.size();
        vector<vector<int> > ret;
        ret.clear();
        if(n <= 3) return ret;
        sort(nums.begin(), nums.end());
        for(int i = 0;i < n-3;i++){
            if(i != 0 && nums[i]==nums[i-1]) continue;
            for(int j = i+1;j < n-2;j++){
                if(j != i+1 && nums[j]==nums[j-1]) continue;
                l = j+1, r = n-1;
                while(l < r){
                    int t = nums[i]+nums[j]+nums[l]+nums[r];
                    if(t < target) ++l;
                    else if(t > target) --r;
                    else if(l != j+1 && nums[l]==nums[l-1]) ++l;
                    else if(r != n-1 && nums[r]==nums[r+1]) --r;
                    else{
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        ret.push_back(v);
                        ++l,--r;
                    }
                }
            }
        }
        return ret;
    }
};
