// Recursive Solution

class Solution {
public:
    int dp[2001][2001];
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof dp);
        return solve(s.size(), p.size(), s, p);
    }
    bool solve(int ns, int np, string& s, string& p) {
        if(ns==0 && np==0) {
            return true;
        }
        if(np==0 && ns>0) {
            return false;
        }
        if(np>0 && ns==0) {
            for(int i=0; i<np; i++) {
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(dp[ns][np]!=-1) return dp[ns][np];
        if(s[ns-1]==p[np-1] || p[np-1]=='?') {
            return dp[ns][np] = solve(ns-1, np-1, s, p);
        }
        if(p[np-1]=='*') {
            int a = solve(ns-1, np, s, p);
            int b = solve(ns, np-1, s, p);
            return dp[ns][np] = a | b;
        }
        return dp[ns][np] = false;
    }
};

// Iterative Solution

class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size(), np = p.size();
        vector<vector<int>> dp(np+1, vector<int>(ns+1));
        dp[0][0] = 1;
        for(int i=1; i<=np; i++) {
            if(p[i-1]=='*') {
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int i=1; i<=np; i++) {
            for(int j=1; j<=ns; j++) {
                if(p[i-1]=='?' || p[i-1]==s[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }       
                else if(p[i-1]=='*') {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
            }
        }
        return dp[np][ns];
    }
};