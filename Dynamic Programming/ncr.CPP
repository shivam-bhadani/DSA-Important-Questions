class Solution{
public:
    int nCr(int n, int r){
        if(r>n) return 0;
        int MOD = 1e9 + 7;
        if(r>n-r) r = n - r;
        vector<int> dp(r+1);
        dp[0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=min(i,r); j>=0; j--) {
                dp[j] = (dp[j] + dp[j-1])%MOD;
            }
        }
        return dp[r];
    }
};