class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int ans = 0;
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(i==n-1 || j==m-1) {
                    ans = max(ans, mat[i][j]);
                    continue;
                }
                if(mat[i][j]==0) {
                    continue;
                }
                else {
                    mat[i][j] = 1 + min({mat[i][j+1], mat[i+1][j], mat[i+1][j+1]});
                    ans = max(ans, mat[i][j]);
                }
            }
        }
        return ans;
    }
};