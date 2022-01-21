class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> a;
        for(int i=0; i<nums.size(); i++) {
            for(auto& j: nums[i]) {
                a.push_back({j, i});
            }
        }
        sort(a.begin(), a.end());
        
        int n = a.size(), total = 0, diff = INT_MAX;
        vector<int> mp(nums.size());
        vector<int> ans = {INT_MIN, INT_MAX};
        int i = 0;
        for(int j=0; j<n; j++) {
            mp[a[j].second]++;
            if(mp[a[j].second] == 1) total++;
            if(total == nums.size()) {
                if(a[j].first - a[i].first < diff) {
                    diff = a[j].first - a[i].first;
                    ans[0] = a[i].first; ans[1] = a[j].first;
                }
            }
            while(1) {
                if(mp[a[i].second] > 1) {
                    mp[a[i].second]--;
                    i++;
                }
                else {
                    break;
                }
            }
            if(total==nums.size() && a[j].first - a[i].first < diff) {
                diff = a[j].first - a[i].first;
                ans[0] = a[i].first; ans[1] = a[j].first;
            }
        }
        return ans;
    }
};