class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]] = i;
        }
        for(int i=0; i<n; i++) {
            int x = target - nums[i];
            if(mp.find(x)!=mp.end() && mp[x]!=i) {
                vector<int> ans = {i, mp[x]};
                return ans;
            }
        }
        return {};
    }
};