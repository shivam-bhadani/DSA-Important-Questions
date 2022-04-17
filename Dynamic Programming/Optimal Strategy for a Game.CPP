// Recursive Solution

class Solution{
    public:
    long long dp[1001][1001];
    long long maximumAmount(int arr[], int n){
        memset(dp, -1, sizeof(dp));
        return solve(arr, 0, n-1);
    }
    long long solve(int arr[], int i, int j) {
        if(i>j) return 0;
        if(i==j) return arr[i];
        if(dp[i][j]!=-1) return dp[i][j];
        long long ans1 = arr[i] + min(solve(arr, i+2, j), solve(arr, i+1, j-1));
        long long ans2 = arr[j] + min(solve(arr, i+1, j-1), solve(arr, i, j-2));
        return dp[i][j] = max(ans1, ans2);
    }
};

// Iterative Solution
// Gap Strategy

class Solution{
    public:
    long long maximumAmount(int arr[], int n){
        vector<vector<int>> dp(n, vector<int>(n));
        for(int g=0; g<n; g++) {
            for(int i=0,j=g; j<n; i++,j++) {
                if(g==0) {
                    dp[i][j] = arr[i];
                }
                else if(g==1) {
                    dp[i][j] = max(arr[i], arr[j]);
                }
                else {
                    int lft = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
                    int rght = arr[j] + min(dp[i+1][j-1], dp[i][j-2]);
                    dp[i][j] = max(lft, rght);
                }
            }
        }
        return dp[0][n-1];
    }
};