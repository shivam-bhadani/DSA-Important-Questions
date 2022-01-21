class Solution {
public:
    int nextGreaterElement(int n) {
        string s;
        while(n) {
            s.push_back(n%10+'0');
            n/=10;
        }
        reverse(s.begin(), s.end());
        int sz = s.size();
        int i = sz - 2;
        while(i>=0 && s[i]>=s[i+1]) i--;
        if(i==-1) return -1;
        int j = sz - 1;
        while(j>=0 && s[i]>=s[j]) j--;
        if(j==-1) return -1;
        swap(s[i], s[j]);
        reverse(s.begin()+i+1, s.end());
        long long ans = 0;
        for(auto& c: s) {
            ans = 10*ans + (c-'0');
            if(ans>INT_MAX) return -1;
        }
        return ans;
    }
};