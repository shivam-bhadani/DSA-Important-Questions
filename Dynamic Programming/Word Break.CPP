class Solution {
public:
    int dp[305];
    bool solve(int curr, string& s, set<string>& st) {
        if(curr>=s.size()) return 1;
        if(dp[curr]!=-1) return dp[curr];
        string prefix;
        int ans = 0;
        for(int i=curr; i<s.size(); i++) {
            prefix.push_back(s[i]);
            if(st.count(prefix)) {
                ans |= solve(i+1, s, st);
            }
        }
        return dp[curr] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        memset(dp, -1, sizeof dp);
        for(auto& s: wordDict) {
            st.insert(s);
        }
        return solve(0, s, st);
    }
};