class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(arr[i]<=k) cnt++;
        }
        int i=0, j=0, bad=0;
        int ans = cnt;
        while(j<n) {
            if(arr[j]>k) bad++;
            if(j - i + 1 == cnt) {
                ans = min(ans, bad);
                if(arr[i] > k) bad--;
                i++; 
            } 
            j++;
        }
        return ans;
    }
};