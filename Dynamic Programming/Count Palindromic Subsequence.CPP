// Recursive Solution

class Solution{
    public:
    long long dp[1001][1001];
    int MOD = 1e9 + 7;
    long long int  countPS(string str)
    {
        memset(dp, -1, sizeof dp);
        return solve(0, str.size()-1, str);
    }
    long long solve(int i, int j, string& s) {
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j] = (1 + solve(i+1, j, s) + solve(i, j-1, s)) % MOD;
        else return dp[i][j] = (MOD + solve(i+1, j, s) + solve(i, j-1, s) - solve(i+1, j-1, s)) % MOD;
    }
     
};

// Iterative Solution
// Gap Strategy

class Solution {
public:
	long long int  countPS(string str)
    {
        int MOD = 1e9 + 7;
        int n = str.size();
        vector<vector<long long>> dp(n, vector<long long>(n));
        for(int g=0; g<n; g++) {
            for(int i=0,j=g; j<n; i++,j++) {
                if(g==0) {
                    dp[i][j] = 1;
                }
                else {
                    if(str[i]==str[j]) {
                        dp[i][j] = (1 + dp[i+1][j] + dp[i][j-1]) % MOD;
                    }
                    else {
                        dp[i][j] = (MOD + dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]) % MOD;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
}