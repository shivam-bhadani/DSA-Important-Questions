class Solution {
public:
    int dp[20];
    int numTrees(int n) {
        memset(dp, -1, sizeof dp);
        return solve(n);
    }
    int solve(int n) {
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans = 0;
        for(int i=1; i<=n; i++) {
            ans += solve(i-1) * solve(n-i);
        }
        return dp[n] = ans;
    }
};