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
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        for(int i = 0;i < n;++i) nums[i] = i+1;
        int i = 1;
        bool flag = true;
        while(i++ < k && flag){
            flag = nextPermutation(nums.begin(), nums.end());
        }
        string ret = "";
        if(flag)
            for(int i = 0;i < n;++i) ret += (nums[i]+'0');
        return ret; 
    }
};
