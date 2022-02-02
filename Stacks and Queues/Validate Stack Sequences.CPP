class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = popped.size(), pop_idx = 0;
        stack<int> st;
        for(auto& i: pushed) {
            st.push(i);
            while(pop_idx<n && !st.empty() && st.top()==popped[pop_idx]) {
                st.pop();
                pop_idx++;
            }
        }
        return pop_idx==n;
    }
};