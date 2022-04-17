// Approach inspired from Matrix Chain Multiplication

// Recursive Solution

class Solution {
public:
    int dp[2001][2001];
    int minCut(string s) {
        memset(dp, -1, sizeof dp);
        return solve(s, 0, s.size()-1);
    }
    
    bool isPalindrome(string& s, int i, int j) {
        while(i<=j) {
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int solve(string& s, int i, int j) {
        if(i>=j) return 0;
        if(isPalindrome(s, i, j)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k=i; k<j; k++) {
            int temp = solve(s, i, k) + solve(s, k+1, j) + 1;
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
};

// Some Optimisation over the recursive solution

class Solution {
public:
    int dp[2001][2001];
    int minCut(string s) {
        memset(dp, -1, sizeof dp);
        return solve(s, 0, s.size()-1);
    }
    
    bool isPalindrome(string& s, int i, int j) {
        while(i<=j) {
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int solve(string& s, int i, int j) {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(isPalindrome(s, i, j)) return 0;
        int ans = INT_MAX;
        
        for(int k=i; k<j; k++) {
            int left, right, temp;
            if(dp[i][k]!=-1) left = dp[i][k];
            else {
                left = solve(s, i, k);
                dp[i][k] = left;
            }
            if(dp[k+1][j]!=-1) right = dp[k+1][j];
            else {
                right = solve(s, k+1, j);
                dp[k+1][j] = right;
            }
            temp = left + right + 1;
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
};

// Iterative Solution
// Gap Strategy

class Solution {
private:
    bool isPalindrome(string& s, int i, int j) {
        while(i<=j) {
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.size();
        int dp[n][n];
        for(int g=0; g<n; g++) {
            for(int i=0,j=g; j<n; i++,j++) {
                if(g==0) {
                    dp[i][j] = 0;
                }
                else if(g==1) {
                    dp[i][j] = !(s[i]==s[j]);
                }
                else {
                    if(isPalindrome(s, i, j)) {
                        dp[i][j] = 0;
                    }
                    else {
                        int val = INT_MAX;
                        for(int k=i; k<j; k++) {
                            val = min(val, 1 + dp[i][k] + dp[k+1][j]);
                        }
                        dp[i][j] = val;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};

// Another Approach and It is optimised frome previous one

// Recursive Solution

class Solution {
private:
     bool isPalindrome(string& s, int i, int j) {
        while(i<=j) {
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
public:
    int dp[2001];
    int minCut(string s) {
        memset(dp, -1, sizeof dp);
        return solve(0, s);
    }
    int solve(int i, string& s) {
        if(i>=s.size()) return 0;
        int n = s.size();
        if(isPalindrome(s, i, n-1)) return 0;
        if(dp[i]!=-1) return dp[i];  
        int ans = INT_MAX; 
        for(int j=i; j<n; j++){ 
            if(isPalindrome(s, i, j)) {
                ans = min(ans, 1 + solve(j+1, s));
            }
        }
        return dp[i] = ans;
    }
};

// Iterative Solution 

class Solution {
private:
    bool isPalindrome(string& s, int i, int j) {
        while(i<=j) {
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n);
        for(int j=0; j<n; j++) {
            if(isPalindrome(s, 0, j)) {
                dp[j] = 0;
                continue;
            }
            int val = INT_MAX;
            for(int i=j; i>=1; i--) {
                if(isPalindrome(s, i, j)) {
                    val = min(val, dp[i-1]);
                }
            }
            dp[j] = 1 + val;
        }
        return dp[n-1];
    }
};