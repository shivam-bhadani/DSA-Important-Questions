class Solution {
public:
    int dp[71][71][71];
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, grid[0].size()-1, grid);
    }
    int solve(int r, int c1, int c2, vector<vector<int>>& grid) {
        if(r>=grid.size() || c1>=grid[0].size() || c2>=grid[0].size() || c1<0 || c2<0) 
            return INT_MIN;
        if(dp[r][c1][c2]!=-1)
            return dp[r][c1][c2];
        
        int dy[] = {-1, 0, +1};
        
        int mxPath = 0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                mxPath = max(mxPath, solve(r+1, c1+dy[i], c2+dy[j], grid));
            }
        }
        if(c1==c2) mxPath += grid[r][c1];
        else mxPath += grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2] = mxPath;
    }
};