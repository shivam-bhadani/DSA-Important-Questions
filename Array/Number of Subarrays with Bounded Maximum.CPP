class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int i=0, j=0, prev=0, ans=0;
        while(j<n) {
            if(nums[j]>=left && nums[j]<=right) {
                prev = j-i+1;
                ans += prev;
            }
            else if(nums[j]<left) {
                ans += prev;
            }
            else if(nums[j]>right) {
                i = j + 1;
                prev = 0;
            }
            j++;
        }
        return ans;
    }
};