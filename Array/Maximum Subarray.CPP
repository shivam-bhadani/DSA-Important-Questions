class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxEnd = nums[0], ans = nums[0];
        for(int i=1; i<n; i++) {
            maxEnd = max(nums[i], maxEnd+nums[i]);
            ans = max(ans, maxEnd);
        }
        return ans;
    }
};