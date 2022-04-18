// Recursive Solution 

class Solution {
public:
    int dp[1005][1005];
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof dp);
        return solve(s.size(), t.size(), s, t);
    }
    int solve(int n, int m, string& s, string& t) {
        if(n<m) return 0;
        if(m==0) return 1;
        if(n==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n-1]==t[m-1]) {
            return dp[n][m] = solve(n-1, m, s, t) + solve(n-1, m-1, s, t);
        }
        else {
            return dp[n][m] = solve(n-1, m, s, t);
        }
    }
};

// Iterative Solution

class Solution {
public:
    typedef unsigned long long ull;
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<ull>> dp(n+1, vector<ull>(m+1));
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        for(int j=1; j<=m; j++) dp[0][j] = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1]==t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};

// Space Optimisation

class Solution {
public:
    typedef unsigned long long ull;
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<ull> dp(m+1);
        dp[0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=m; j>=1; j--) {
                if(s[i-1]==t[j-1]) {
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[m];
    }
};