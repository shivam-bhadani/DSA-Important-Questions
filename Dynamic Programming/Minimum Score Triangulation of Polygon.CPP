// Recursive Solution

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int dp[n][n];
        for(int g=0; g<n; g++) {
            for(int i=0,j=g; j<n; i++,j++) {
                if(g==0) {
                    dp[i][j] = 0;
                }
                else if(g==1) {
                    dp[i][j] = 0;
                }
                else if(g==2) {
                    dp[i][j] = values[i] * values[i+1] * values[j];
                }
                else {
                    int val = INT_MAX;
                    for(int k=i+1; k<=j-1; k++) {
                        int curr = values[i] * values[j] * values[k];
                        int lft = dp[i][k];
                        int rght = dp[k][j];
                        val = min(val, curr + lft + rght);
                    }
                    dp[i][j] = val;
                }
            }
        }
        return dp[0][n-1];
    }
};