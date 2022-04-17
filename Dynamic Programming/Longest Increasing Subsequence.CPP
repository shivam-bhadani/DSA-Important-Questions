// Time = O(n^2)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]>nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// Time = O(nlogn)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = INT_MIN;
        for(int i=0; i<n; i++) {
            int idx = upper_bound(dp.begin(), dp.end(), nums[i])-dp.begin();
            if(nums[i]>dp[idx-1] && nums[i]<dp[idx]) {
                dp[idx] = nums[i];
            }
        }
        for(int i=n; i>=0; i--) {
            if(dp[i]!=INT_MAX) {
                return i;
            }
        }
        return 0;
    }
};