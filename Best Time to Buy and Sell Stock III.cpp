class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int n = prices.size();
        vector<int> preProfit(n,0); // preProfit[i]记录到[0,i]能获得的最大收益
        vector<int> postProfit(n,0);// postProfit[i]记录到[i,n-1]能获得的最大收益
        int minPrice = prices[0];
        for(int i = 1;i < n;++i){ // 从前往后扫描，维护最小的价格
            minPrice = min(minPrice,prices[i]);
            preProfit[i] = max(preProfit[i-1],prices[i]-minPrice);
        }
        int maxPrice = prices[n-1];
        for(int i = n-2;i >= 0;--i){ // 从后往前扫描，维护最大的价格
            maxPrice = max(maxPrice,prices[i]);
            postProfit[i] = max(postProfit[i+1],maxPrice-prices[i]);
        }
        int ans = 0;
        for(int i = 0;i < n;++i)
            ans = max(ans,preProfit[i]+postProfit[i]);
        return ans;
    }
};
