class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
        stack<pair<int, int>> st;
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            if(st.empty()) ans[i] = i+1;
            else if(st.top().first>price[i]) ans[i] = i-st.top().second;
            else {
                while(!st.empty() && st.top().first<=price[i]) st.pop(); 
                if(st.empty()) ans[i] = i+1;
                else ans[i] = i-st.top().second;
            }
            st.push({price[i], i});
        }
        return ans;
    }
};