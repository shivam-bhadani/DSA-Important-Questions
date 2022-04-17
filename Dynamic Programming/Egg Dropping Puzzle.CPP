// Recursive Solution

class Solution
{
    public:
    int dp[201][201];
    int eggDrop(int e, int f) 
    {
        memset(dp, -1, sizeof dp);
        return solve(e, f);
    }
    int solve(int e, int f) {
        if(f<=1 || e==1) {
            return f;
        }
        if(dp[e][f]!=-1) {
            return dp[e][f];
        }
        int ans = INT_MAX;
        for(int k=1; k<=f; k++) {
            int brk = solve(e-1, k-1);
            int survive = solve(e, f - k);
            ans = min(ans, 1 + max(brk, survive));
        }
        return dp[e][f] = ans;
    }
};