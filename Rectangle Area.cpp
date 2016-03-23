class Solution {
public:
    typedef pair<int,int> pii;
    int cover(pii a,pii b){
        // 返回线段a和线段b覆盖的长度,要考虑一条线段包含另一条的情况
        if(b.first<=a.first && a.second<=b.second) return a.second-a.first;
        if(a.first<=b.first && b.second<=a.second) return b.second-b.first;
        return min(a.second-b.first,b.second-a.first);
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = abs(A-C)*abs(B-D),s2 = abs(E-G)*abs(F-H);
        if(s1 == 0 || s2 == 0) return s1+s2; // 处理其中一个矩形为点或者线，面积为0
        if(G>A&&C>E && H>B&&D>F){ // 两个矩形相交
            return s1+s2-cover(make_pair(A,C),make_pair(E,G))*cover(make_pair(B,D),make_pair(F,H));
        }
        else return s1+s2;     
    }
};
