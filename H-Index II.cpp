class Solution {
public:
    int hIndex(vector<int>& citations) {
        int mid,n = citations.size(),l = 0,r = n;
        if(!n) return 0;
        int ans = 0; 
        while(l < r){
            mid = l+r>>1;
            if(citations[mid] >= n-mid){
                ans = max(ans,n-mid);
                r = mid;
            }
            else l = mid+1;
        }
        return ans;
    }
};
