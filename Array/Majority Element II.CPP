class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, ele1 = INT_MAX, ele2 = INT_MAX;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else if(cnt1==0) {
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2==0) {
                ele2 = nums[i];
                cnt2 = 1;
            }
            else {
                cnt1--; cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        if(ele1!=INT_MAX) {
            for(auto& i: nums) {
                if(i==ele1) cnt1++;
            }
        }
        if(ele2!=INT_MAX) {
            for(auto& i: nums) {
                if(i==ele2) cnt2++;
            }
        }
        vector<int> ans;
        if(ele1!=INT_MAX && cnt1>n/3) ans.push_back(ele1);
        if(ele2!=INT_MAX && cnt2>n/3) ans.push_back(ele2);
        return ans;
    }
};