#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
struct Interval{
    int start,end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    struct Point{
        int val,isleft;
        bool operator<(const Point &a)const{
            return val == a.val ? isleft > a.isleft : val < a.val;
        }
    };
    static bool cmp(const Interval &a, const Interval &b){
        return a.start == b.start ? a.end < b.end : a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),cmp);
        vector<Point> v;
        for(int i = 0;i < intervals.size();++i){
            Point l,r;
            l.val = intervals[i].start,l.isleft = 1;
            r.val = intervals[i].end,r.isleft = 0; 
            v.push_back(l),v.push_back(r);
        }
        sort(v.begin(), v.end());
        vector<Interval> ret;
        int start,end,cnt = 0,findLeft = 0;
        for(int i = 0;i < v.size();++i){
            if(v[i].isleft){
                ++cnt;
                if(!findLeft){
                    start = v[i].val;
                    findLeft = 1;
                }
            }
            else{
                --cnt;
                if(cnt == 0){
                    end = v[i].val;
                    findLeft = 0;
                    ret.push_back(Interval(start,end));
                }
            }
        }
        return ret;    
    }
};
int main(){
    int l,r;
    vector<Interval> intervals;
    Solution sol;
    while(cin >> l >> r){
        intervals.push_back(Interval(l,r));
    }
    vector<Interval> ret = sol.merge(intervals);
    for(int i = 0;i < ret.size();++i)
        cout << ret[i].start << ", " << ret[i].end << endl;
    return 0;    
}
