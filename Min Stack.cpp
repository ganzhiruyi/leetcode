class MinStack {
public:
    void push(int x) {
        if(v.empty()){
            minValue = x;
            minValueCnt = 1;
        }
        else{
            if(x == minValue) ++minValueCnt;
            else if(x < minValue) minValue = x,minValueCnt = 1;
        }
        v.push_back(x);
    }

    void pop() {
        if(v.empty()) return;
        if(v.back() == minValue) --minValueCnt;
        v.erase(v.end()-1);
        if(!minValueCnt && !v.empty()){
            minValue = v[0],minValueCnt = 1;
            for(int i = 1;i < v.size();++i)
                if(v[i] == minValue) ++minValueCnt;
                else if(v[i] < minValue) minValue = v[i],minValueCnt = 1;
        }
    }

    int top() {
        return v.back();
    }

    int getMin() {
        return minValue;
    }
private:
    vector<int> v;
    int minValue,minValueCnt;
};
