class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n);
        int ans = arr[n-1] - arr[0];
        for(int i=1; i<n; i++) {
            if(arr[i]>=k) {
                int mn = min(arr[i]-k, arr[0]+k);
                int mx = max(arr[i-1]+k, arr[n-1]-k);
                ans = min(ans, mx - mn);
            }
        }
        return ans;
    }
};
