class Solution {
public:
    vector<int> C; // 下标从1开始
    int nn; // 离散化后有多少的数
    int lowbit(int x){
        return x & (-x);
    }
    void update(int x,int val){
        while(x <= nn){
            C[x] += val;
            x += lowbit(x);
        }
    }
    int query(int x){
        int ret = 0;
        while(x){
            ret += C[x];
            x -= lowbit(x);
        }
        return ret;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(!n) return vector<int>();
        vector<int> v;
        for(int i = 0;i < nums.size();++i)
            v.push_back(nums[i]);
        // 离散化
        sort(v.begin(), v.end());
        nn = unique(v.begin(), v.end())-v.begin();
        // 从后往前，统计右边已经有多少个小于nums[i]的数了
        vector<int> ret(n);
        C = vector<int>(nn+1,0);
        for(int i = n-1;i >= 0;--i){
            // 树状数组的下标从1开始，所以idx要加1
            int idx = lower_bound(v.begin(),v.begin()+nn,nums[i])-v.begin()+1;
            ret[i] = query(idx-1); // 查询小于idx的值，所以idx-1
            update(idx,1);
        }
        return ret;
    }
};
