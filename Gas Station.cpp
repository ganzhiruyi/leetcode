// 版本一：暴力枚举,超时
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int allgas = 0,allcost = 0,n = gas.size();
        typedef pair<int,int> pii;
        vector<pii> tgas;
        for(int i = 0;i < n;++i){
            allgas += gas[i];
            allcost += cost[i];
            tgas.push_back(make_pair(gas[i],i));
        }
        if(allcost > allgas) return -1;
        sort(tgas.begin(), tgas.end());
        reverse(tgas.begin(), tgas.end());
        int nowgas;
        for(int i = 0;i < n;++i){
            int start = tgas[i].second;
            nowgas = gas[start]-cost[start];
            if(nowgas < 0) continue;
            int j = (start+1)%n;
            while(j != start){
                nowgas += gas[j]-cost[j];
                if(nowgas < 0) break;
                j = (j+1)%n;
            }
            if(j == start) return start;
        }
        return -1;
    }
};
// 版本二
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0,n = gas.size(),totalLeft = 0,sum = 0;
        for(int i = 0;i < n;++i){
            int diff = gas[i]-cost[i];
            totalLeft += diff;
            sum += diff;
            if(sum < 0){
                start = i+1;
                sum = 0;
            }
        }
        return totalLeft >= 0 ? start : -1;
    }
};
