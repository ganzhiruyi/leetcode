class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0,r = height.size()-1,ans = 0;
        vector<int> v = height;
        if(r <= 0) return 0;
        ans = min(v[l],v[r])*(r-l);
        while(l < r){
            if(v[l] < v[r]){
                int tmp = v[l];
                while(l < r && v[l] <= tmp) l++;
                ans = max(ans,min(v[r],v[l])*(r-l));
            }
            else{
                int tmp = v[r];
                while(l < r && v[r] <= tmp) r--;
                ans = max(ans,min(v[r],v[l])*(r-l));
            }
        }
        return ans;
    }
};
