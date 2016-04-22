class Solution {
public:
    bool isDigit(char ch){
        return '0'<=ch&&ch<='9';
    }
    struct Node{
        // isNum:1 for num,0 for '('
        int val,isNum;
        Node(){}
        Node(int v,int s):val(v),isNum(s){}
    };
    int calculate(string s) {
        int num,topNum,n = s.length();
        stack<char> opStack;
        stack<Node> numStack;
        for(int i = 0;i < n;++i){
            if(s[i] == ' ') continue;
            if(s[i]=='+'||s[i]=='-')
                opStack.push(s[i]);
            else if(s[i]=='(')
                numStack.push(Node(0,0));
            else if(s[i]==')'){
                topNum = numStack.top().val;
                numStack.pop();
                numStack.pop(); // pop '(' from numStack
                num = topNum;
                while(!numStack.empty()&&numStack.top().isNum){
                    topNum = numStack.top().val;
                    numStack.pop();
                    char op = opStack.top();
                    opStack.pop();
                    num = op=='+' ? topNum+num : topNum-num;
                }
                numStack.push(Node(num,1));
            }
            else{
                num = 0;
                while(i < n && isDigit(s[i])){
                    num = num*10 + (s[i]-'0');
                    ++i;
                }
                --i;
                while(!numStack.empty()&&numStack.top().isNum){
                    topNum = numStack.top().val;
                    numStack.pop();
                    char op = opStack.top();
                    opStack.pop();
                    num = op=='+' ? topNum+num : topNum-num;
                }
                numStack.push(Node(num,1));
            }
        }
        return numStack.top().val;
    }
};
