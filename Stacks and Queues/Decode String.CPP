class Solution {
public:
    string decodeString(string s) {
        stack<int> st1;
        stack<char> st2;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i]==']') {
                int no_of_occ = st1.top();
                st1.pop();
                string part;
                while(st2.top()!='[') {
                    part.push_back(st2.top());
                    st2.pop();
                }
                st2.pop();
                reverse(part.begin(), part.end());
                string put;
                for(int j=0; j<no_of_occ; j++) {
                    put += part;
                }
                for(auto& c: put) {
                    st2.push(c);
                }
            }
            else if(s[i]=='[') {
                st2.push(s[i]);
            }
            else if(s[i]>='a' && s[i]<='z') {
                st2.push(s[i]);
            }
            else {
                int num = 0;
                while(s[i]!='[') {
                    num = (num*10) + (s[i]-'0');
                    i++;
                }
                i--;
                st1.push(num);
            }
        }
        string ans;
        while(!st2.empty()) {
            ans.push_back(st2.top());
            st2.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};