class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        vector<int> primes;
        primes.push_back(2);
        int tk,k = 3;
        while(k <= n){
            tk = k;
            for(int i = 0;i < primes.size();++i)
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
