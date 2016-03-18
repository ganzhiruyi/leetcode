// 版本一：直接搜索,TLE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return dfs(0,0,prices);
    }
    int dfs(int pre,int cur,vector<int>& prices){
        int ret = 0;
        if(cur >= prices.size()) return 0;
        if(pre == cur) return max(dfs(pre,cur+1,prices),dfs(pre+1,cur+1,prices));
        if(prices[cur] > prices[pre]){
            ret = dfs(cur,cur+1,prices);
            ret = max(dfs(cur+2,cur+2)+prices[cur]-prices[pre],ret);
        }
        return ret;
    }
};
/* 版本二：动态规划
buy[i]表示第i天最终持有股票能获得的最大收益
sell[i]表示第i天卖出股票/处于冷却导致最终没有股票能获得的最大收益
转移方程:
buy[i] = max{buy[i-1],sell[i-2]-price[i]} i>=2
buy[i] = max{buy[i-1],-price[i]} i<2
注意当i<2时，因为还没卖出，所以收益都为负;
sell[i] = max{sell[i-1],buy[i-1]+price[i]}
初始条件buy[0]=-prices[0],sell[0]=0;
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int n = prices.size();
        vector<int> buy(n,0);
        vector<int> sell(n,0);
        buy[0] = -prices[0];
        for(int i = 1;i < n;++i){
            if(i >= 2) buy[i] = max(buy[i-1],sell[i-2]-prices[i]);
            else buy[i] = max(buy[i-1],-prices[i]);
            sell[i] = max(sell[i-1],buy[i-1]+prices[i]);
        }
        return sell[n-1];
    }
};
// 压缩空间
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int n = prices.size();
        int buy = -prices[0],sell = 0,preSell = 0;
        for(int i = 1;i < n;++i){
            int tmp = sell;
            if(i >= 2) buy = max(buy,preSell-prices[i]);
            else buy = max(buy,-prices[i]);
            sell = max(sell,buy+prices[i]);
            preSell = tmp;
        }
        return sell;
    }
};
