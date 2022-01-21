class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> twoPower(n);
        twoPower[0] = 1;
        for(int i=1; i<n; i++) {
            twoPower[i] = (twoPower[i-1] * 2) % MOD;
        }
        long long ans = 0;
        for(int i=0; i<n; i++) {
            ans = (ans + nums[i]*twoPower[i] - nums[i]*twoPower[n-i-1]) % MOD;
        }
        return ans;
    }
};