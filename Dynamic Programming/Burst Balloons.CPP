// Recursive Solution

class Solution {
public:
    int dp[301][301];
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return solve(0, nums.size()-1, nums);
    }
    int solve(int i, int j, vector<int>& nums) {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MIN;
        for(int k=i; k<=j; k++) {
            int lft = solve(i, k-1, nums);
            int rght = solve(k+1, j, nums);
            int curr = nums[k];
            if(i-1>=0) curr *= nums[i-1];
            if(j+1<nums.size()) curr *= nums[j+1];
            ans = max(ans, lft + rght + curr);
        }
        return dp[i][j] = ans;
    }
};

// Iterative Solution
// Gap Strategy

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];
        for(int g=0; g<n; g++) {
            for(int i=0,j=g; j<n; i++,j++) {
                int val = INT_MIN;
                for(int k=i; k<=j; k++) {
                    int lft = k==i ? 0 : dp[i][k-1];
                    int rght = k==j ? 0 : dp[k+1][j];
                    int curr = nums[k];
                    if(i-1>=0) curr *= nums[i-1];
                    if(j+1<n) curr *= nums[j+1];
                    val = max(val, lft + rght + curr);
                }
                dp[i][j] = val;
            }
        }
        return dp[0][n-1];
    }
};