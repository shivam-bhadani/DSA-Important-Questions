class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        for(auto& c: s) {
            if(!st1.empty() && c=='#') st1.pop();
            if(c!='#') st1.push(c);
        }
        for(auto& c: t) {
            if(!st2.empty() && c=='#') st2.pop();
            if(c!='#') st2.push(c);
        }
        if(st1.size()!=st2.size()) return false;
        while(!st1.empty()) {
            if(st1.top()!=st2.top()) return false;
            st1.pop(); st2.pop();
        }
        return true;
    }
};