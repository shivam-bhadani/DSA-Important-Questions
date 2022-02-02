class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> st;
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--) {
            if(st.empty()) ans[i] = 0;
            else if(st.top().first>temperatures[i]) ans[i] = st.top().second-i;
            else {
                while(!st.empty() && st.top().first<=temperatures[i]) st.pop();
                if(st.empty()) ans[i] = 0;
                else ans[i] = st.top().second-i;
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};