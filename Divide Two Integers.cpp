typedef long long ll;
class Solution {
public:
    int divide(int dividend, int divisor) {
    	bool negative = (dividend>0 && divisor<0) || (dividend<0 && divisor>0);
    	ll a = abs((ll)dividend), b = abs((ll)divisor),ans = 0;
    	while(a >= b){
    		int shift = 0;
    		while((b << shift) <= a) shift++;
    		ans += (1 << shift-1);
    		a -= (b << shift-1);
    	}
    	return negative ? -ans : ans;
    }
};
