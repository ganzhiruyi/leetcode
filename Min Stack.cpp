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
    // pop操作是O(n)的
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
// 版本二，使用一个辅助栈,存储当前最小值
class MinStack {
public:
    // 对于minv而言,只有它为空或者x<=minv.top()才把它加入到栈minv中
    void push(int x) {
        v.push(x);
        if(minv.empty() || x <= minv.top()) minv.push(x);
    }
    // pop操作
    void pop() {
        int x = v.top();
        v.pop();
        if(x == minv.top())
            minv.pop(); // 删除如果是合法的，一定有minv.top()存在且最小
    }

    int top() {
        return v.top();
    }

    int getMin() {
        return minv.top();
    }
private:
    stack<int> v;
    stack<int> minv;
};

