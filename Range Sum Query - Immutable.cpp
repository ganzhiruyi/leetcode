class NumArray {
public:
    vector<int> a;
    NumArray(vector<int> &nums) {
        a.clear();
        for(int i = 0;i < nums.size();++i)
            if(i == 0) a.push_back(nums[i]);
            else a.push_back(nums[i]+a[i-1]);
    }
    int sumRange(int i, int j) {
        if(i == 0) return a[j];
        return a[j]-a[i-1];
    }
};
