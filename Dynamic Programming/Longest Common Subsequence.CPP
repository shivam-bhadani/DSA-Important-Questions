// Recursive Solution

class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof dp);
        return solve(text1.size(), text2.size(), text1, text2);
    }
    int solve(int n, int m, string& s1, string& s2) {
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n-1]==s2[m-1]) return dp[n][m] = 1 + solve(n-1, m-1, s1, s2);
        else return dp[n][m] = max(solve(n-1, m, s1, s2), solve(n, m-1, s1, s2));
    } 
};

// Iterative Solution

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                if(i==0 || j==0) {
                    dp[i][j] = 0;
                }
                else if(s1[i-1]==s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};