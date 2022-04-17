class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 1, p3 = 1, p5 = 1;
        vector<int> dp(n+1);
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            int two_mul = 2 * dp[p2];
            int three_mul = 3 * dp[p3];
            int five_mul = 5 * dp[p5];
            int mn = min({two_mul, three_mul, five_mul});
            dp[i] = mn;
            if(mn==two_mul) {
                p2++;
            }
            if(mn==three_mul) {
                p3++;
            }
            if(mn==five_mul) {
                p5++;
            }
        }
        return dp[n];
    }
};