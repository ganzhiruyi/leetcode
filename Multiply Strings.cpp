class Solution {
public:
    void print(deque<int>& a, string name){
        string ret = "";
        for(int i = a.size()-1;i >= 0;--i)
            ret += (a[i]+'0');
        cout << name <<": "<<ret << endl; 
    }
    void addTwo(deque<int>& a,deque<int>& b){
        int i,tmp,up = 0;
        for(i = 0;i < a.size() && i < b.size();++i){
            tmp = a[i]+b[i]+up;
            a[i] = tmp%10;
            up = tmp/10;
        }
        while(i < b.size()){
            tmp = b[i]+up;
            up = tmp/10;
            a.push_back(tmp%10);
            ++i;
        }
        if(up) a.push_back(up);
    }
    string multiply(string num1, string num2) {
        int a,b,up,n = num1.length(),m = num2.length();
        deque<int> ans(m,0);
        for(int i = n-1;i >= 0;--i){
            int tmp,a = num1[i]-'0';
            up = 0;
            deque<int> add;
            for(int j = m-1;j >= 0;--j){
                b = num2[j]-'0';
                tmp = a*b+up;
                up = tmp/10;
                add.push_back(tmp%10);
            }
            if(up) add.push_back(up);
            int cnt = n-i-1;
            while(cnt-- > 0) add.push_front(0);
            addTwo(ans,add);
        }
        string ret = "";
        if(ans[ans.size()-1]==0) return "0";
        for(int i = ans.size()-1;i >= 0;--i)
            ret += (ans[i]+'0');
        return ret;
    }
};
