class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftMax(n+1), rightMin(n+1);
        leftMax[0] = arr[0];
        for(int i=1; i<n; i++) {
            leftMax[i] = max(leftMax[i-1], arr[i]);
        }
        leftMax[n] = leftMax[n-1];
        rightMin[n] = INT_MAX;
        for(int i=n-1; i>=0; i--) {
            rightMin[i] = min(rightMin[i+1], arr[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(leftMax[i]<=rightMin[i+1])
                ans++;
        }
        return ans;
    }
};