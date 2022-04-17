// Solution inspired from catlan number

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n; 
    n -= 2;
    vector<int> dp(n+1);
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; i++) {
        int j = i-1;
        int k = 0;
        while(k<i) {
            dp[i] += (dp[j]*dp[k]);
            j--; k++;
        }
    }
    cout << dp[n];
}