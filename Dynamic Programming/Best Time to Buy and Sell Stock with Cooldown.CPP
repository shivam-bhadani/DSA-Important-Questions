// Recursive Solution

class Solution {
public:
    int dp[5001];
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return solve(prices, 0, prices.size());
    }
    int solve(vector<int>& prices, int curr, int n) {
        if(curr>=n)
          return 0;
        if(dp[curr]!=-1)
            return dp[curr];
        
        int mxVal = 0;
        for(int i=curr+1; i<n; i++) {
            mxVal = max(mxVal, prices[i]-prices[curr]+solve(prices, i+2, n));
        }
        mxVal = max(mxVal, solve(prices, curr+1, n));
        return dp[curr] = mxVal;
    }
};

// Iterative Solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = -prices[0], sell = 0, cool = 0;
        for(int i=1; i<n; i++) {
            int nbuy = cool - prices[i];
            int nsell = buy + prices[i];
            int ncool = sell;
            buy = max(buy, nbuy);
            sell = max(sell, nsell);
            cool = max(cool, ncool);
        }
        return sell;
    }
};