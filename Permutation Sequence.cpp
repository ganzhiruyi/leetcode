// 版本一： 根据nextPermutation和prePermutation选择从左边或者右边遍历第k个，TLE
class Solution {
public:
    typedef vector<int>::iterator iterator;
    bool nextPermutation(iterator first, iterator last){
        if(first == last) return false;
        iterator i = last;
        --i;
        if(i == first) return false;
        for(;;){
            iterator ii = i;
            --i;
            if(*i < *ii){
                iterator j = last-1;
                while(!(*i < *j)) --j;
                swap(*i,*j);
                reverse(ii,last);
                return true;
            }
            if(i == first){
                reverse(first,last);
                return false;
            }
        }
    }
    bool prePermutation(iterator first,iterator last){
        if(first == last) return false;
        iterator i = last;
        --i;
        if(i == first) return false;
        for(;;){
            iterator ii = i;
            --i;
            if(*i > *ii){
                iterator j = last-1;
                while(!(*i > *j)) --j;
                swap(*i,*j);
                reverse(ii,last);
                return true;
            }
            if(i == last){
                reverse(first,last);
                return false;
            }
        }
    }
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        bool flag;
        int all = 1;
        for(int i = 1;i <= n;++i) all *= i;
        if(k <= all/2){
            for(int i = 0;i < n;++i) nums[i] = i+1;
            int i = 1;
            flag = true;
            while(i++ < k && flag){
                flag = nextPermutation(nums.begin(), nums.end());
            }
        }
        else{
            for(int i = n;i > 0;--i) nums[n-i] = i;
            int i = 1;
            flag = true;
            k = all-k+1;
            while(i++ < k && flag){
                flag = prePermutation(nums.begin(), nums.end());
            }
        }
        string ret = "";
        if(flag)
            for(int i = 0;i < n;++i) ret += (nums[i]+'0');
        return ret; 
    }
};
// 版本二 AC    
class Solution {
public:
    static const int N = 9;
    int factorial[N+1],used[N+1];
    string getPermutation(int n, int k) {
        factorial[0] = 1;    
        for(int i = 1;i <= n;++i){
            factorial[i] = factorial[i-1]*i;
            used[i] = 0;
        }
        int curBit,tn = n;
        string ret = "";
        while(k){
            curBit = k/factorial[n-1];
            if(k%factorial[n-1]) ++curBit;
            int cnt = 0;
            for(int i = 1;i <= tn;++i){
                if(used[i]) continue;
                if(++cnt == curBit){
                    used[i] = 1;
                    ret += (i+'0');
                    break;
                }
            }
            k = k%factorial[n-1];
            --n;
        }
        // 剩下的数字逆序输出即可
        for(int i = tn;i >= 1;--i){
            if(used[i]) continue;
            used[i] = 1;
            ret += (i+'0');
        }
        return ret;
    }
};

