class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<int> primes;
        primes.push_back(2);
        int tk,k = 3;
        while(k < n){
            tk = k;
            int tmp = sqrt(tk*1.0)+1;
            for(int i = 0;i < primes.size() && primes[i] <= tmp;++i)
                if(tk % primes[i] == 0){
                    tk /= primes[i];
                    break;
                }
            if(tk == k) primes.push_back(k);
            k += 2;
        }
        return primes.size();
    }
};
// 线性筛求小于n素数的个数,O(n*lglgn)
class Solution {
public:
    int countPrimes(int n) {
        bool isPrime[n];
        for(int i = 2;i < n;++i) isPrime[i] = true;
        for(int i = 2;i*i < n;++i){
            if(!isPrime[i]) continue;
            for(int j = i*i;j < n;j += i)
                isPrime[j] = false;
        }
        int cntPrimes = 0;
        for(int i = 2;i < n;++i)
            cntPrimes += isPrime[i] ? 1 : 0;
        return cntPrimes;
    }
};
