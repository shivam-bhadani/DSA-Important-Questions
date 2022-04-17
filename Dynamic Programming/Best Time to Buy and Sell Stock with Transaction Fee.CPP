// Recursive Solution

class Solution {
public:
    int dp[50001];
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof dp);
        return solve(prices, 0, prices.size(), fee);
    }
    int solve(vector<int>& prices, int curr, int n, int fee) {
        if(curr>=n) 
            return 0;
        if(dp[curr]!=-1)
            return dp[curr];
        
        int mxVal = 0;
        for(int i=curr+1; i<n; i++) {
            mxVal = max(mxVal, prices[i]-prices[curr]-fee+solve(prices, i+1, n, fee));
        }
        mxVal = max(mxVal, solve(prices, curr+1, n, fee));
        return dp[n] = mxVal;
    }
};


// Iterative Solution

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = -prices[0], sell = 0;
        for(int i=1; i<n; i++) {
            int nbuy = sell - prices[i];
            int nsell = buy + prices[i] - fee;
            buy = max(buy, nbuy);
            sell = max(sell, nsell);
        }
        return sell;
    }
};