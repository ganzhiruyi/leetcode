// 版本一：参照Merge Intervals,先加入这个newInterval，再进行merge 604ms
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        struct Point{
            int val,isleft;
            bool operator<(const Point &a)const{
                return val == a.val ? isleft > a.isleft : val < a.val;
            }
        };
        intervals.push_back(newInterval);
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
// 版本二,因为刚开始的所有区间都相离，并且按照区间的开始时间排序 588ms
class Solution {
public:
    static bool cmp(const Interval &a, const Interval &b){
        return a.start == b.start ? a.end < b.end : a.start < b.start;
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int l = newInterval.start,r = newInterval.end;
        vector<Interval> ret;
        int startMerge = 0; // 1表示已经开始合并newInterval，0表示还没开始合并
        int mergeL = l; // 初始化避免{[1,5]}中插入[6,7]这种情况mergeL没有值
        int endMerge = 0; // 1表示完成合并newInterval,0表示还没完成 
        for(int i = 0;i < intervals.size();++i){
            if(l > intervals[i].end){
                ret.push_back(intervals[i]);
            }
            else if(r < intervals[i].start){
                ret.push_back(intervals[i]);
            }
            else{
                if(!startMerge){
                    mergeL = min(intervals[i].start,mergeL);
                    startMerge = 1;
                    if(r <= intervals[i].end){
                        ret.push_back(Interval(mergeL,intervals[i].end));
                        endMerge = 1;
                    }
                }
                else{
                    if(r <= intervals[i].end){
                        ret.push_back(Interval(mergeL,intervals[i].end));
                        endMerge = 1;
                    }
                }
            }
        }
        if(!endMerge)
            ret.push_back(Interval(mergeL,r));
        // 因为上面的循环可能导致newInterval小却放到了最后
        sort(ret.begin(), ret.end(),cmp); 
        return ret;
    }
};
