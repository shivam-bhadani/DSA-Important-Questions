class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> lastOcc(26);
        for(int i=0; i<n; i++) {
            lastOcc[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int prev = -1, mx = 0;
        for(int i=0; i<n; i++) {
            mx = max(mx, lastOcc[s[i]-'a']);
            if(mx==i) {
                ans.push_back(i-prev);
                prev = i;
            }
        }
        return ans;
    }
};