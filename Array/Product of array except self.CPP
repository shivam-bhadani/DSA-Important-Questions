class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = nums[0];
        for(int i=1; i<n; i++) {
            ans[i] = ans[i-1]*nums[i];
        }
        int rightProduct = 1;
        for(int i=n-1; i>=0; i--) {
            if(i==0) {
                ans[i] = rightProduct;
            }
            else if(i==n-1) {
                ans[i] = ans[i-1];
            }
            else {
                ans[i] = rightProduct*ans[i-1];
            }
            rightProduct *= nums[i];
        }
        return ans;
    }
};