// Recursive Solution

class Solution {
public:
    int dp[1001][101][2];
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return solve(prices, 0, prices.size(), false, k);
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

// Iterative Solution I 
// Time Complexity = O(n^3)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // dp[i][j] store max profit upto i-th day from j transaction
        int dp[k+1][n];
        for(int i=0; i<=k; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 || j==0) {
                    dp[i][j] = 0;
                    continue;
                }
                int mxProfit = dp[i][j-1];
                for(int d=j; d>=0; d--) {
                    mxProfit = max(mxProfit, dp[i-1][d] + prices[j] - prices[d]);
                }
                dp[i][j] = mxProfit;
            }
        }
        return n>=1 ? dp[k][n-1] : 0;
    }
};

// Iterative Solution
// Time Complexity = O(n^2)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int dp[k+1][n];
        for(int i=0; i<=k; i++) {
            int prefMax = INT_MIN;
            for(int j=0; j<n; j++) {
                if(i==0 || j==0) {
                    dp[i][j] = 0;
                    continue;
                }
                prefMax = max(prefMax, dp[i-1][j-1] - prices[j-1]);
                dp[i][j] = max(dp[i][j-1], prefMax + prices[j]);
            }
        }
        return n>=1 ? dp[k][n-1] : 0;
    }
};