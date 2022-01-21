class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool isOne = false;
        for(int i=0; i<n; i++) {
            if(nums[i]==1) isOne = true;
            if(nums[i]<1 || nums[i]>n) {
                nums[i] = 1;
            }
        }
        if(!isOne) return 1;
        for(int i=0; i<n; i++) {
            int ind = abs(nums[i]) - 1;
            nums[ind] = -abs(nums[ind]);
        }
        for(int i=0; i<n; i++) {
            if(nums[i]>=0) {
                return (i+1);
            }
        }
        return (n+1);
    }
};