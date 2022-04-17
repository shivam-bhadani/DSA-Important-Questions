 // Approach based on the Ugly Number II

class Solution {
public:

    typedef long long ll;

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<ll> p(primes.size()+1, 1);
        ll dp[n+1];
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            ll mn = INT_MAX;
            for(int j=0; j<primes.size(); j++) {
                mn = min(mn, primes[j]*1LL*dp[p[j]]);
            }
            for(int j=0; j<primes.size(); j++) {
                if(mn == primes[j]*1LL*dp[p[j]]) p[j]++;
            }
            dp[i] = mn;
        }
        return dp[n];
    }
};

// Optimised Approach

class Solution {
public:
    
    typedef long long ll;
    
    class Data {
    public:
        ll ptr, prime, val;
        Data(ll x, ll y, ll z) {
            prime = x;
            ptr = y;
            val = z;
        }
    };
    
    class Compare {
    public:
        bool operator()(Data d1, Data d2) {
            return d1.val>d2.val;
        }    
    };
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<Data, vector<Data>, Compare> pq;
        vector<ll> dp(n+1);
        dp[1] = 1;
        for(auto& i: primes) {
            pq.push(Data(i, 1, i));
        }
        int i=2; 
        while(i<=n) {
            Data curr = pq.top();
            pq.pop();
            if(curr.val!=dp[i-1]) {
                dp[i] = curr.val;
                i++;
            }
            pq.push(Data(curr.prime, curr.ptr+1, curr.prime*dp[curr.ptr+1]));
        }
        return dp[n];
    }
};