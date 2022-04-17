typedef long long ll;

void kadane(vector<ll>& maxSum, ll a[], ll n) {
    maxSum[0] = max(a[0], 0LL);
    for(int i=1; i<n; i++) {
        maxSum[i] = max(maxSum[i-1]+a[i], a[i]);
        maxSum[i] = max(maxSum[i], 0LL);
    }
}

long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    vector<ll> maxSum(n);
    kadane(maxSum, a, n);
    vector<ll> prefSum(n);
    prefSum[0] = a[0];
    ll ans = 0;
    for(int i=0; i<k; i++) {
        ans += a[i];
    }
    for(int i=1; i<n; i++) {
        prefSum[i] = prefSum[i-1] + a[i];
    }
    for(int i=k; i<n; i++) {
        ll temp = prefSum[i] - prefSum[i-k];
        temp += maxSum[i-k];
        ans = max(ans, temp);
    }
    return ans;
}