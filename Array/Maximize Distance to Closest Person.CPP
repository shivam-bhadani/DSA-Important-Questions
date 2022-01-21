class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = INT_MIN;
        int i=0, j=1, n=seats.size();
        while(j<n) {
            while(j<n && seats[j]==0) j++;
            if(j==n) ans = max(ans, j-i-1);
            else if(seats[i]==0) ans = max(ans, j-i);
            else ans = max(ans, (j-i)/2);
            i = j;
            j++;
        }
        return ans;
    }
};