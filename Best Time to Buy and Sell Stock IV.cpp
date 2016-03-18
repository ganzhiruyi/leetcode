class Solution {
public:
    /*
    local[i][j]:表示到第i天，进行j次交易能获得的局部最优值，且最后一次交易在第i天完成
    global[i][j]：表示到第i天，进行j次交易能获得的全局最优值
    转移方程：
    local[i][j]=max{global[i-1][j-1]+max(0,diff),local[i-1][j]+diff}
    global[i][j]=max{global[i-1][j],local[i][j]}
    由于每一维只与前一维有关，可以倒序状态压缩
    */
    int maxProfit(int k, vector<int>& prices) {
        if(!prices.size()) return 0;
        int n = prices.size();
        if(k >= n) return maxProfit2(prices); // k大于n，即II问题
        vector<int> local(k+1,0);
        vector<int> global(k+1,0);
        for(int i = 1;i < n;++i){
            for(int j = k;j > 0;--j){
                int diff = prices[i]-prices[i-1];
                local[j] = max(global[j-1]+max(0,diff),local[j]+diff);
                global[j] = max(local[j],global[j]);
            }
        }
        return global[k];
    }
    int maxProfit2(vector<int>& prices){
        int ans = 0;
        for(int i = 1;i < prices.size();++i)
            ans += max(0,prices[i]-prices[i-1]);
        return ans;
    }
};
