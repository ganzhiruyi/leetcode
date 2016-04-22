class Solution {
public:
    int ans;
    void dfs(int pre,int sum,int product,int numCnt){
        if(sum == 0){
            if(numCnt >= 2)
                ans = max(ans,product);
            return;
        }
        for(int i = 1;i <= sum;++i){
            if(i < pre) continue;
            dfs(i,sum-i,product*i,numCnt+1);
        }
    }
    int integerBreak(int n) {
        ans = n-1;
        dfs(0,n,1,0);
        return ans;
    }
};
