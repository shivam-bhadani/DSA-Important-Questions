// Time = O(n), Space = O(n)

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(s[i]=='(') st.push(i);
            else {
                st.pop();
                if(!st.empty())
                    ans = max(ans, i-st.top());
                else st.push(i);
            }
        }
        return ans;
    }
};

// Time = O(n), Space = O(1)

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int open = 0, close = 0, ans = 0;
        for(int i=0; i<n; i++) {
            if(s[i]=='(') open++;
            else close++;
            if(open==close) ans = max(ans, open+close);
            if(close>open) open = 0, close = 0;
        }
        open = 0, close = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i]=='(') open++;
            else close++;
            if(open==close) ans = max(ans, open+close);
            if(open>close) open = 0, close = 0;
        }
        return ans;
    }
};