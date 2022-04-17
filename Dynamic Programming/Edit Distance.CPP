// Recursive Solution

class Solution {
public:
    int dp[501][501];
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);
        return solve(word1.size(), word2.size(), word1, word2);
    }
    int solve(int n1, int n2, string& s1, string& s2) {
        if(n1==0 || n2==0) {
            return abs(n1 - n2);
        }
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        if(s1[n1-1]==s2[n2-1]) {
            return dp[n1][n2] = solve(n1-1, n2-1, s1, s2);
        }
        int insrt = 1 + solve(n1, n2-1, s1, s2);
        int delte = 1 + solve(n1-1, n2, s1, s2);
        int replce = 1 + solve(n1-1, n2-1, s1, s2);
        return dp[n1][n2] = min({insrt, delte, replce});
    }
};

// Iterative Solution

class Solution {
public:
    int minDistance(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        for(int i=0; i<=n1; i++) {
            for(int j=0; j<=n2; j++) {
                if(i==0 || j==0) {
                    dp[i][j] = abs(i - j);
                }
                else if(s1[i-1]==s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                }
            }
        }
        return dp[n1][n2];
    }
};