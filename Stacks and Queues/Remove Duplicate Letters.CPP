class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26);
        for(auto& c: s) 
            freq[c-'a']++;
        vector<bool> done(26);
        stack<char> st;
        for(auto& c: s) {
            freq[c-'a']--;
            if(done[c-'a']) continue;
            while(!st.empty() && freq[st.top() -'a']>0 && st.top()>c) {
                done[st.top()-'a'] = false;
                st.pop();
            }
            st.push(c);
            done[c-'a'] = true;
        }
        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};