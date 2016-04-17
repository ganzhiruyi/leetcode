class Solution {
public:
    int partition(vector<int>& nums,int l,int r){
        int i = l-1,pivot = nums[r];
        for(int j = l;j < r;++j){
            if(nums[j] <= pivot)
                swap(nums[++i],nums[j]);
        }
        swap(nums[i+1],nums[r]);
        return i+1;
    }
    int find(vector<int>& nums,int l,int r,int k){
        if(l == r) return nums[l];
        if(l < r){
            int p = partition(nums,l,r);
            if(k == p-l+1) return nums[p];
            else if(k < p-l+1) return find(nums,l,p-1,k);
            else return find(nums,p+1,r,k-p+l-1);
        }
        return -1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums,0,nums.size()-1,nums.size()-k+1);
    }
};
