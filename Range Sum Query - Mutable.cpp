#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
class NumArray {
public:
    vector<int> C;
    vector<int> A;
    int n;
    NumArray(vector<int> &nums) {
        C = vector<int>(nums.size()+1,0); // C,A数组下标需要从1开始
        A = vector<int>(nums.size()+1,0);
        n = nums.size();
        for(int i = 0;i < n;++i) update(i,nums[i]);
    }
    int lowbit(int x){
        return x&(-x);
    }
    void update(int i, int val) {
        ++i;
        int add = val - A[i],x = i;
        while(x <= n){
            C[x] += add;
            x += lowbit(x);
        }
        A[i] = val; // 更新C完成后，更新A
    }
    int Sum(int x){
        int ret = 0;
        while(x){
            ret += C[x];
            x -= lowbit(x);
        }
        return ret;
    }
    int sumRange(int i, int j) {
        ++i,++j;
        return Sum(j)-Sum(i-1);
    }
};
int main(){
    vector<int> a;
    for(int i = 0;i <= 10;++i) a.push_back(i);
    NumArray arr = NumArray(a);
    cout << arr.sumRange(0,9) << endl;
    cout << arr.sumRange(10,10) << endl;
    cout << arr.sumRange(4,7) << endl;
    arr.update(1,4);
    cout << arr.sumRange(0,3) << endl;
    cout << arr.sumRange(0,0) << endl;
    return 0;
}
