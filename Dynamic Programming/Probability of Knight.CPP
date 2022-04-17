class Solution{
	public:
	double findProb(int N,int start_x, int start_y, int steps)
	{
	    double dp[N][N][steps+1];
	    int dx[] = {-2, -1, +1, +2, +2, +1, -1, -2};
	    int dy[] = {+1, +2, +2, +1, -1, -2, -2, -1};
	    for(int x=0; x<N; x++) {
	        for(int y=0; y<N; y++) dp[x][y][0] = 1;
	    }
	    for(int step=1; step<=steps; step++) {
	        for(int x=0; x<N; x++) {
	            for(int y=0; y<N; y++) {
	                dp[x][y][step] = 0;
	                for(int i=0; i<8; i++) {
            	       int newX = x+dx[i];
            	       int newY = y+dy[i];
            	       if(newX>=0 && newX<N && newY>=0 && newY<N) {
            	           dp[x][y][step]+=dp[newX][newY][step-1]/8.0;
            	       }
                    }
	            }
	        }
	    }
	    return dp[start_x][start_y][steps];
	}
};