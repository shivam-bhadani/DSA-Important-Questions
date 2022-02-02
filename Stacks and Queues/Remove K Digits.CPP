class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && k>0 && st.top()>num[i]) {
                k--; 
                st.pop();
            }
            st.push(num[i]);
        }
        while(k>0) {
            st.pop(); k--;
        }
        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.back()=='0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        if(ans.empty()) return "0";
        return ans;
    }
};