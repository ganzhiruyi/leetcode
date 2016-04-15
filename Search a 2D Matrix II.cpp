// 版本一 O(nlogn)
class Solution {
public:
    bool searchRow(vector<int> &row,int target){
        int mid,l = 0,r = row.size()-1;
        while(l <= r){
            mid = l+r>>1;
            if(row[mid] == target) return true;
            else if(row[mid] < target) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(!n) return false;
        int m = matrix[0].size();
        for(int i = 0;i < n;++i){
            if(matrix[i][0]<=target&&target<=matrix[i][m-1]){
                if(searchRow(matrix[i],target))
                    return true;
            }
        }
        return false;
    }
};
// 版本一，O(nlogn)
class Solution {
public:
    bool searchRow(vector<int> &row,int target){
        int mid,l = 0,r = row.size()-1;
        while(l <= r){
            mid = l+r>>1;
            if(row[mid] == target) return true;
            else if(row[mid] < target) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
    bool search(vector<vector<int>>& matrix,int l,int r,int target){
        int mid;
        if(l > r) return false;
        int m = matrix[l].size();
        if(l== r && matrix[l][0]<=target&&target<=matrix[l][m-1])
            return searchRow(matrix[l],target);
        if(l < r){
            mid = l+r>>1;
            if(matrix[mid][0]==target||matrix[mid][m-1]==target)
                return true;
            if(matrix[mid][m-1] < target)
                return search(matrix,mid+1,r,target);
            else if(matrix[mid][0] > target)
                return search(matrix,l,mid-1,target);
            else{
                return search(matrix,l,mid,target)||search(matrix,mid+1,r,target);
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(!n) return false;
        return search(matrix,0,n-1,target);
    }
};
// 从右上角搜索，O(n+m)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(!n) return false;
        int m = matrix[0].size();
        int i = 0,j = m-1;
        while(i < n && j >= 0){
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target) --j;
            else ++i;
        }
        return false;
    }
};

