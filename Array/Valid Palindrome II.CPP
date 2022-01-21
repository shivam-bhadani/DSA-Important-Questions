class Solution {
private:
    bool isPalindrome(string& s, int lo, int hi) {
        while(lo<=hi) {
            if(s[lo] == s[hi]) {
                lo++; hi--;
            }
            else return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i<=j) {
            if(s[i] == s[j]) {
                i++; j--;
            }
            else {
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }
        return true;
    }
};