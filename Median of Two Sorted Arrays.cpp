class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int k = m+n;
        if(k%2==1) return findMedian(A,m,B,n,(k+1)/2);
        return (findMedian(A,m,B,n,k/2)+findMedian(A,m,B,n,k/2+1))/2;
    }
    
    double findMedian(int A[],int m,int B[],int n,int k){
        if(m > n) return findMedian(B,n,A,m,k);
        if(m == 0) return B[k-1];
        if(n == 0) return A[k-1];
        if(k==1) return min(A[0],B[0]);
        int la = min(m,k/2);
        int lb = k-la;
        if(A[la-1] <= B[lb-1]) return findMedian(A+la,m-la,B,n,k-la);
        else return findMedian(A,m,B+lb,n-lb,k-lb);
    }
};
