class Solution{
  public:
    int fun(string &s) {
        int n = s.size();
        int MOD = 1e9 + 7;
        int a = 0, ab = 0, abc = 0;
        // a denotes no. of subsequence of type a upto i-th index
        // ab denotes no. of subsequence of type ab upto i-th index
        // abc denotes no. of subsequence of type abc upto i-th index
        
        for(int i=0; i<n; i++) {
            if(s[i]=='a') {
                a = (2*1LL*a + 1) % MOD;
            }
            else if(s[i]=='b') {
                ab = (2*1LL*ab + a) % MOD;
            }
            else if(s[i]=='c') {
                abc = (2*1LL*abc + ab) % MOD;
            }
        }
        return abc;
    }
};