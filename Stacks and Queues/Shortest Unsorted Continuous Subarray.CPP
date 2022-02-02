class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int hi = -1, mx = nums[0];
        for(int i=1; i<n; i++) {
            if(nums[i]<mx) {
                hi = i;
            }
            else {
                mx = max(mx, nums[i]);
            }
        }
        int lo = 0, mn = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            if(nums[i]>mn) {
                lo = i;
            }
            else {
                mn = min(mn, nums[i]);
            }
        }
        return hi - lo + 1;
    }
};