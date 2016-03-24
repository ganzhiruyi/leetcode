// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int mid,l = 0,r = n; // 下标从0开始，这样保证不会超过INT_MAX
        while(l < r){
            mid = l+(r-l>>1);
            if(isBadVersion(mid+1)) r = mid; // 注意这里要传入mid+1
            else l = mid+1;
        }
        return r+1; // 这里r+1跟mid+1道理一样，因为下标是从0开始，答案从1开始
    }
};
