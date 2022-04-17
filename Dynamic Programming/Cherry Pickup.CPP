class Solution {
public:
    int dp[51][51][51][51];
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        int n = grid.size(), m = grid[0].size();
        int ans = solve(0, 0, 0, 0, grid);
        return ans<0 ? 0 : ans;
    }
    int solve(int r1, int c1, int r2, int c2, vector<vector<int>>& grid) {
        if(r1>=grid.size() || r2>=grid.size() || c1>=grid[0].size() || c2>=grid[0].size() || grid[r1][c1]==-1 || grid[r2][c2]==-1) 
            return INT_MIN;
        if(r1==grid.size()-1 && c1==grid[0].size()-1)
            return grid[r1][c1];
        if(dp[r1][c1][r2][c2]!=-1) 
            return dp[r1][c1][r2][c2];
        
        int cherries = 0;
        if(r1==r2 && c1==c2) {
            cherries = grid[r1][c1];
        }
        else {
            cherries = grid[r1][c1] + grid[r2][c2];
        }
        
        int path1 = solve(r1+1, c1, r2+1, c2, grid); //vv
        int path2 = solve(r1+1, c1, r2, c2+1, grid); //vh
        int path3 = solve(r1, c1+1, r2+1, c2, grid); //hv
        int path4 = solve(r1, c1+1, r2, c2+1, grid); //hh
        
        cherries += max(max(path1, path2), max(path3, path4));
        return dp[r1][c1][r2][c2] = cherries;
    }
};