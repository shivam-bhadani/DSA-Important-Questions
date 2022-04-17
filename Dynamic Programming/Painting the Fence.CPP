class Solution{
    public:
    long long countWays(int n, int k){
        int mod = 1e9 + 7;
        vector<long long> dp(n+1);
        dp[1] = k; dp[2] = k*k;
        for(int i=3; i<=n; i++) {
            dp[i] = ((k-1)*(dp[i-1] + dp[i-2])) % mod;
        }
        return dp[n];
    }
};