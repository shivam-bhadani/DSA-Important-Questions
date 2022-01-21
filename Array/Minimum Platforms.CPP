class Solution {
public:
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n); sort(dep, dep + n);
        int j = 0, ans = 0;
        for(int i=0; i<n; i++) {
            if(arr[i]>dep[j]) {
                j++;
            }
            else {
                ans++;
            }
        }
        return ans;
    }
};