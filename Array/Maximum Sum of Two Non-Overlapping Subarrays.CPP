class Solution {
private:
    int solve(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> dp1(n), dp2(n);
        // dp1[i] store maxSum of subarray of length firstLen from left to i-th index
        int sum = 0;
        for(int i=0; i<n; i++) {
            if(i<firstLen) {
                sum += nums[i];
                dp1[i] = sum;
            }
            else {
                sum += nums[i] - nums[i-firstLen];
                dp1[i] = max(dp1[i-1], sum);
            }
        }
        // dp2[i] store maxSum of subarray of length secondLen from right to i-th index
        sum = 0;
        for(int i=n-1; i>=0; i--) {
            if(n-i<=secondLen) {
                sum += nums[i];
                dp2[i] = sum;
            }
            else {
                sum += nums[i] - nums[i+secondLen];
                dp2[i] = max(dp2[i+1], sum);
            }
        }
        int ans = 0;
        for(int i=firstLen-1; i<n-secondLen; i++) {
            ans = max(ans, dp1[i] + dp2[i+1]);
        }
        return ans;
    }
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(solve(nums, firstLen, secondLen), solve(nums, secondLen, firstLen));
    }
};