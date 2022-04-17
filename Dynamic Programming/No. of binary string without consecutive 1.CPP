class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    int mod = 1e9 + 7;
	    ll zero = 1, one = 1;
	    for(int i=2; i<=n; i++) {
	        ll nzero = (zero + one)%mod;
	        ll none = zero;
	        zero = nzero;
	        one = none;
	    }
	    return (zero + one)%mod;
	}
};