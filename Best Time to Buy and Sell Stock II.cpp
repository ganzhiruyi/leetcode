class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int minPrice,maxPrice;
        minPrice = maxPrice = prices[0];
        int ans = 0;
        for(int i = 1;i < prices.size();++i){
            if(prices[i] >= maxPrice){
                maxPrice = prices[i];
            }
            else{
                ans += (maxPrice-minPrice);
                minPrice = maxPrice = prices[i];
            }
        }
        return ans += (maxPrice-minPrice);
    }
};
