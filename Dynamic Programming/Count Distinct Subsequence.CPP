#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s; 
    cin >> s;
    int n = s.size();
    vector<ll> dp(n+1);
    dp[0] = 1;
    map<char, ll> mp;
    for(int i=1; i<=n; i++) {
        dp[i] = 2*dp[i-1];
        if(mp.find(s[i-1])!=mp.end()) {
            int j = mp[s[i-1]];
            dp[i] -= dp[j-1];
        }
        mp[s[i-1]] = i;
    }
    cout << dp[n] - 1;
}