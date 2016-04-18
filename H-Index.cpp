class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size(),ans = 0;
        for(int i = 0;i < n;++i)
            if(citations[i] >= n-i)
                ans = max(ans,n-i);
        return ans;
    };
};
