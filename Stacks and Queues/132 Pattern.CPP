class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMin(n);
        prefixMin[0] = nums[0];
        for(int i=1; i<n; i++) {
            prefixMin[i] = min(prefixMin[i-1], nums[i]);
        }
        stack<int> st;
        for(int j=n-1; j>=0; j--) {
            while(!st.empty() && st.top()<=prefixMin[j]) st.pop();
            if(!st.empty() && st.top()<nums[j]) return true;
            st.push(nums[j]);
        }
        return false;
    }
};