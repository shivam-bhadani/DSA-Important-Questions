class Solution {
private:
    void solveConfig(string& s, int lo, int hi) {
        if(s[lo]=='L' && s[hi]=='R') {
            return;
        }
        else if(s[lo]=='L' && s[hi]=='L') {
            for(int i=lo; i<hi; i++) {
                s[i] = 'L';
            }
        }
        else if(s[lo]=='R' && s[hi]=='R') {
            for(int i=lo; i<hi; i++) {
                s[i] = 'R';
            }
        }
        else {
            int between = hi - lo - 1;
            int mid = (lo + hi)/2;
            if(between % 2 == 0) {
                for(int i=lo; i<=mid; i++) s[i] = 'R';
                for(int i=mid+1; i<hi; i++) s[i] = 'L';
            }
            else {
                for(int i=lo; i<mid; i++) s[i] = 'R';
                for(int i=mid+1; i<hi; i++) s[i] = 'L';
            }
        }
    }
public:
    string pushDominoes(string dominoes) {
        dominoes.insert(dominoes.begin(), 'L');
        dominoes.push_back('R');
        int i=0, j=1, n=dominoes.size();
        while(j<n) {
            while(dominoes[j]=='.') j++;
            if(i<j)
                solveConfig(dominoes, i, j);
            i = j;
            j++;
        }
        dominoes.erase(dominoes.begin());
        dominoes.pop_back();
        return dominoes;
    }
};