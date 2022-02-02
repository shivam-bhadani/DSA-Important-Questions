class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0, n = s.size();
        for(char c: s) {
            if(c==')') balance--;
            else balance++;
            if(balance<0) return false;
        }
        if(balance==0) return true;
        balance = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i]=='(') balance--;
            else balance++;
            if(balance<0) return false;
        }
        return true;
    }
};