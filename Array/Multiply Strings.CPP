class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int len1 = num1.size(), len2 = num2.size();
        vector<int> res(len1 + len2);
        int skip = 0;
        int i = len2 - 1;
        while(i>=0) {
            int ival = num2[i] - '0';
            int j = len1 - 1;
            int k = res.size() - 1 - skip;
            int carry = 0;
            while(j>=0 || carry>0) {
                int jval = j>=0 ? num1[j] - '0' : 0;
                int pro = ival * jval + carry + res[k];
                res[k] = pro % 10;
                carry = pro / 10;
                j--;
                k--;
            }
            skip++;
            i--;
        }
        string ans;
        int flag = 1;
        for(auto& i: res) {
            if(flag && i==0) continue;
            flag = 0;
            ans.push_back(i + '0');
        }
        return ans;
    }
};