// Time = O(n^2)

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        
        // sorting on the basis of width
        sort(envelopes.begin(), envelopes.end());
        
        // longest increasing subsequence on the basis of height
        vector<int> dp(n, 1);
        int ans = 1;
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(envelopes[j][1]<envelopes[i][1] && envelopes[j][0]<envelopes[i][0]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};

// Time = O(nlogn)

class Solution {
private:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[0]!=b[0] ? a[0]<b[0] : a[1]>b[1];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // sort according to width
        sort(envelopes.begin(), envelopes.end(), compare);
        // LIS on the basis of heights
        vector<int> dp(n+1, INT_MAX);
        dp[0] = INT_MIN;
        for(int i=0; i<n; i++) {
            int idx = upper_bound(dp.begin(), dp.end(), envelopes[i][1])-dp.begin();
            if(dp[idx-1]<envelopes[i][1] && dp[idx]>envelopes[i][1])
                dp[idx] = envelopes[i][1];
        }
        for(int i=n; i>=1; i--) {
            if(dp[i]!=INT_MAX)
                return i;
        }
        return 1;
    }
};