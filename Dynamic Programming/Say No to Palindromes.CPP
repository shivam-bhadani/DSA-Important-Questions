#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m; string s; cin >> n >> m >> s;
    vector<string> make = {"abc", "acb", "bac", "bca", "cab", "cba"};
    vector<vector<int>> track(6, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<6; j++) {
            if(s[i]!=make[j][i%3]) {
                track[j][i] = 1;
            }
        }
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<6; j++) {
            track[j][i] += track[j][i-1];
        }
    }
    while(m--) {
        int l, r; cin >> l >> r; l--; r--;
        int ans = INT_MAX;
        for(int i=0; i<6; i++) {
            if(l-1>=0) ans = min(ans, track[i][r] - track[i][l-1]);
            else ans = min(ans, track[i][r]);
        }
        cout << ans << '\n';
    }
}