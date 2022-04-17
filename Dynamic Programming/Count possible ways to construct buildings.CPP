class Solution{
	public:
	int TotalWays(int N)
	{
	    int building = 1, space = 1;
	    int mod = 1e9+7;
	    for(int i=1; i<N; i++) {
	        int nspace = (space + 0LL + building)%mod;
	        int nbuilding = space;
	        space = nspace;
	        building = nbuilding;
	    }
	    int oneSide = (building + 0LL + space)%mod;
	    int ans = (oneSide*1LL*oneSide)%mod;
	    return ans;
	}
};