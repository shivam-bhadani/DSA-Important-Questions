// Recursive Solution I

class Solution {
public:
    int dp[100001][3];
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return solve(prices, 0, prices.size(), 2);
    }
    int solve(vector<int>& prices, int curr, int n, int t) {
        if(curr>=n || t==0)
            return 0;
        if(dp[curr][t]!=-1)
            return dp[curr][t];
        
        int mxVal = 0;
        for(int i=curr+1; i<n; i++) {
            mxVal = max(mxVal, prices[i]-prices[curr]+solve(prices, i+1, n, t-1));
        }
        mxVal = max(mxVal, solve(prices, curr+1, n, t));
        return dp[curr][t] = mxVal;
    }
};

// Recursive Solution II

class Solution {
public:
    int dp[100001][3][2];
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return solve(prices, 0, prices.size(), false, 2);
    }
    int solve(vector<int>& prices, int curr, int n, bool bought, int t) {
        if(curr>=n || t==0)
            return 0;
        if(dp[curr][t][bought]!=-1)
            return dp[curr][t][bought];
        
        int mxVal = solve(prices, curr+1, n, bought, t);
        if(bought) {
            mxVal = max(mxVal, prices[curr] + solve(prices, curr+1, n, false, t-1));
        }
        else {
            mxVal = max(mxVal, -prices[curr] + solve(prices, curr+1, n, true, t));
        }
        return dp[curr][t][bought] = mxVal;
    }
};

// Iterative Solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp1(n), dp2(n);
        
        // dp1 will store maximum profit of buy sell from left to i-th index
        int minLeft = prices[0];
        dp1[0] = 0;
        for(int i=1; i<n; i++) {
            minLeft = min(minLeft, prices[i]);
            dp1[i] = max(dp1[i-1], prices[i]-minLeft);
        }
        
        // dp2 will store maximum profit of buy sell from right to i-th index
        int maxRight = prices[n-1];
        dp2[n-1] = 0;
        for(int i=n-2; i>=0; i--) {
            maxRight = max(maxRight, prices[i]);
            dp2[i] = max(dp2[i+1], maxRight - prices[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, dp1[i] + dp2[i]);
        }
        return ans;
    }
};