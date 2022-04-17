// Recursive Solution

class Solution{
public:
    int dp[101][101];
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof dp);
        return solve(1, N-1, arr);
    }
    int solve(int i, int j, int arr[]) {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for(int k=i; k<j; k++) {
            int temp = solve(i, k, arr) + solve(k+1, j, arr) + arr[i-1]*arr[k]*arr[j];
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
};

// Iterative Solution 
// Gap Strategy

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int dp[N-1][N-1];
        for(int g=0; g<N-1; g++) {
            for(int i=0,j=g; j<N-1; i++, j++) {
                if(g==0) {
                    dp[i][j] = 0;
                }
                else if(g==1) {
                    dp[i][j] = arr[i]*arr[j]*arr[j+1];
                }
                else {
                    int val = INT_MAX;
                    for(int k=i; k<j; k++) {
                        int left_cost = dp[i][k];
                        int right_cost = dp[k+1][j];
                        int multiply_cost = arr[i] * arr[k+1] * arr[j+1];
                        int total = left_cost + right_cost + multiply_cost;
                        val = min(val, total);
                    }
                    dp[i][j] = val;
                }
            }
        }
        return dp[0][N-2];
    }
};