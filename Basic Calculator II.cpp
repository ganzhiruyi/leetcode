class Solution {
public:
    bool isDigit(char ch){
        return '0'<=ch&&ch<='9';
    }
    bool cmp(char a,char b){
        if(a=='+' || a=='-')
            return b=='+' || b=='-';
        return true;
    }
    int oper(int a,int b,char op){
        if(op == '+') return a+b;
        if(op == '-') return a-b;
        if(op == '*') return a*b;
        if(op == '/') return a/b;
    }
    int calculate(string s) {
        int num,topNum,n = s.length();
        stack<int> numStack;
        stack<char> opStack;
        for(int i = 0;i < n;++i){
            if(s[i]==' ') continue;
            if(isDigit(s[i])){
                num = 0;
                while(i < n && isDigit(s[i])){
                    num = num*10+(s[i]-'0');
                    ++i;
                }
                if(i < n){
                    char nextOp = s[i];
                    while(!numStack.empty()&&!opStack.empty()){
                        char op = opStack.top();
                        topNum = numStack.top();
                        if(cmp(op,nextOp)){
                            num = oper(topNum,num,op);
                            numStack.pop();
                            opStack.pop();
                        }
                        else break;
                    }
                    numStack.push(num);
                }
                else numStack.push(num);
                --i;
            }
            else opStack.push(s[i]);
        }
        num = numStack.top();
        numStack.pop();
        while(!numStack.empty()){ // 栈中还有元素
            topNum = numStack.top();
            num = oper(topNum,num,opStack.top());
            numStack.pop();
            opStack.pop();
        }
        return num;
    }
};
