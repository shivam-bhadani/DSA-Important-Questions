class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> rightMaxInd(n);
        rightMaxInd[n-1] = n-1;
        for(int i=n-2; i>=0; i--) {
            if(s[i]>s[rightMaxInd[i+1]]) {
                rightMaxInd[i] = i;
            }
            else {
                rightMaxInd[i] = rightMaxInd[i+1];
            }
        }
        for(int i=0; i<n; i++) {
            if(s[rightMaxInd[i]]==s[i]) continue;
            swap(s[i], s[rightMaxInd[i]]);
            break;
        }
        int ans = stoi(s);
        return ans;
    }
};