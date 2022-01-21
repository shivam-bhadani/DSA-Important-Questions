class Solution {
private:
    int kadane(vector<int>& arr) {
        int n = arr.size();
        int ans = arr[0], maxEnd = arr[0];
        for(int i=1; i<n; i++) {
            maxEnd = max(maxEnd+arr[i], arr[i]);
            ans = max(ans, maxEnd);
        }
        return ans<0?0:ans;
    }
public:
    const int MOD = 1e9 + 7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if(k == 1) {
            return kadane(arr);
        }
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();
        
        for(int i=0; i<n; i++) arr.push_back(arr[i]);
        
        if(sum < 0) return kadane(arr);
        else return (kadane(arr) + 0LL + ((k-2)*1LL*sum)%MOD)%MOD;
    }
};