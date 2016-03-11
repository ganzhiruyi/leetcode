class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        int mid,v,l = 0,r = n*m-1;
        while(l <= r){
            mid = l+r>>1;
            v = matrix[mid/m][mid%m];
            if(v == target) return true;
            else if(v < target) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
};
