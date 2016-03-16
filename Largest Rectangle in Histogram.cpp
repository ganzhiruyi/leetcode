// 版本一：O(nlgn)
class Solution {
public:
    typedef pair<int,int> pii;
    int findLargest(vector<vector<pii>> &f,int l,int r){
        /** 先利用RMQ O(1)找到最小值及其下标idx
            递归查找左右[l,idx-1],[idx+1,r]
            最大值在左右最小值以及（当前最小值*(r-l+1))中得到
        **/
        if(l > r) return 0;
        if(l == r) return f[l][0].second;
        int k = log(double(r-l+1))/log(2.0);
        pii smallest;
        if(f[l][k].second < f[r-(1<<k)+1][k].second)
            smallest = f[l][k];
        else smallest = f[r-(1<<k)+1][k];
        int ls = findLargest(f,l,smallest.first-1);
        int rs = findLargest(f,smallest.first+1,r);
        return max(max(ls,rs),smallest.second*(r-l+1));
    }
    int largestRectangleArea(vector<int>& heights) {
        if(!heights.size()) return 0;
        int n = heights.size();
        int k = log(double(n))/log(2.0)+2;
        vector<vector<pii>> f(n,vector<pii>(k)); // f[i][j]:[i,i+2^j)区间的最小值
        // 这里不要构建n*n矩阵，会MLE，n*lg(n)就行,+2避免出现2^lg(n) < n的情况RE
        // 初始化RMQ
        for(int i = 0;i < n;++i) f[i][0] = make_pair(i,heights[i]);
        for(int j = 1;(1<<j) <= n;++j)
            for(int i = 0;i+(1<<j)-1 < n;++i){
                if(f[i][j-1].second < f[i+(1<<j-1)][j-1].second)
                    f[i][j] = f[i][j-1];
                else f[i][j] = f[i+(1<<j-1)][j-1];
            }
        return findLargest(f,0,n-1);
    }
};
// 版本二 O(n)
/** 利用一个stack来维护一个递增序列，栈中每个元素表示长方形的下标，
对于第i个长方形高度x,首先比较它和栈顶的长方形的高度heights[top],
1、如果x>=heights[top],单调栈的性质得到保持，x入栈,继续下一个长方形
2、如果x<heights[top],top出栈，新的栈顶元素为s.top，则以heights[top]为矩形的高度,
可知(s.top,i)之间的区间的长方形的高度均大于等于heights[top]，所以求出此时的局部面积；
3、按照2一直执行直到heights[s.top] <= heights[i]
4、i走到n,判断栈是否为空,非空执行2,3步
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(!heights.size()) return 0;
        int n = heights.size();
        stack<int> st;
        int area,tp,i = 0,ret = 0;
        while(i < n){
            if(st.empty() || heights[st.top()] <= heights[i]){
                st.push(i++);
            }
            else{
                tp = st.top();
                st.pop();
                if(st.empty()) area = heights[tp]*i; // 栈为空，证明之前的高度均>heights[i]，所以i个
                else area = heights[tp]*(i-st.top()-1); // 这里求长度左边是以新栈顶st.top为边界
                ret = max(ret,area);
            }
        }
        while(!st.empty()){
            tp = st.top();
            st.pop();
            if(st.empty()) area = heights[tp]*i;
            else area = heights[tp]*(i-st.top()-1); // 此时i==n
            ret = max(ret,area);
        }
        return ret;
    }
};
