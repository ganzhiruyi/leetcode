class Solution {
public:
    int largestRectangle(int *height,int n){
        stack<int> st;
        int tp,area,i = 0,maxArea = 0;
        while(i < n){
            if(st.empty() || height[st.top()] <= height[i])
                st.push(i++);
            else{
                tp = height[st.top()];
                st.pop();
                if(!st.empty())
                    area = tp*(i-1-st.top());
                else area = tp*i;
                if(area > maxArea) maxArea = area;
            }
        }
        while(!st.empty()){ // 弹出stack中剩余的矩形
            tp = height[st.top()];
            st.pop();
            if(!st.empty())
                area = tp*(i-1-st.top());
            else area = tp*i;
            if(area > maxArea) maxArea = area;
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0; 
        int n = matrix[0].size();
        int f[m][n]; // 表示第i行及以上的第j列形成的只含有1的矩形的高度
        for(int j = 0;j < n;++j) f[0][j] = matrix[0][j]=='1' ? 1 : 0;
        for(int i = 1;i < m;++i)
            for(int j = 0;j < n;++j)
                f[i][j] = matrix[i][j]=='1' ? f[i-1][j]+1 : 0;
        int area,ans = 0;
        for(int i = 0;i < m;++i){
            area = largestRectangle(f[i],n);
            if(ans < area) ans = area;
        }
        return ans;
    }
};
