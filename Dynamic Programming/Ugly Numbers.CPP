class Solution {
public:
    bool isUgly(int n) {
        if(n<1) return false;
        vector<int> primes = {2, 3, 5};
        for(auto& i: primes) {
            while(n%i==0) {
                n /= i;
            }
        }
        return n==1;
    }
};