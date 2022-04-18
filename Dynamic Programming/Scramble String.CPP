class Solution {
public:
    map<pair<string, string>, int> dp;
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
    int solve(string s1, string s2) {
        if(s1==s2) return 1;
        if(s1.size()==1) return 0;
        if(dp.find({s1, s2})!=dp.end()) return dp[{s1, s2}];
        int n = s1.size();
        for(int i=1; i<n; i++) {
            int a = solve(s1.substr(0, i), s2.substr(n-i, i)) && solve(s1.substr(i, n-i), s2.substr(0, n-i));
            int b = solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n-i), s2.substr(i, n-i));
            if(a | b) return dp[{s1, s2}] = true;
        }
        return dp[{s1, s2}] = false;
    }
};