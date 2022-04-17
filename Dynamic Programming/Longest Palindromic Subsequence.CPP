class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.size();
        string s2;
        for(int i=n-1; i>=0; i--) s2.push_back(s1[i]);
        return lcs(s1, s2);
    }
    int lcs(string& s1, string& s2) {
        int n = s1.size();
        int dp[n+1][n+1];
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                if(i==0 || j==0) dp[i][j] = 0;
                else if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][n];
    }
};