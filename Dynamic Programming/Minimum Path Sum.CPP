// Recursive Solution

class Solution {
public:
    int dp[201][201];
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, grid.size()-1, grid[0].size()-1, grid);
    }
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if(i==n && j==m) {
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int right = INT_MAX, down = INT_MAX;
        if(i+1<grid.size())
            right = solve(i+1, j, n, m, grid);
        if(j+1<grid[0].size())
            down = solve(i, j+1, n, m, grid);
        return dp[i][j] = grid[i][j] + min(right, down);
    }
};

// Iterative Solution

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(i==n-1 && j==m-1) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int right = INT_MAX, down = INT_MAX;
                if(i+1<n) right = dp[i+1][j];
                if(j+1<m) down = dp[i][j+1];
                dp[i][j] = grid[i][j] + min(right, down);
            }
        }
        return dp[0][0];
    }
};