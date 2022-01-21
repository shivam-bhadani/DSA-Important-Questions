class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i=0, j=n-1, k=n-1;
        while(i<=j) {
            int val1 = nums[i]*nums[i];
            int val2 = nums[j]*nums[j];
            if(val1>val2) {
                ans[k--] = val1;
                i++;
            }
            else {
                ans[k--] = val2;
                j--;
            }
        }
        return ans;
    }
};