int countRev (string s)
{
    if(s.size() & 1) return -1;
    int open = 0, close = 0;
    for(auto& c: s) {
        if(c=='{') open++;
        else if(c=='}' && open>0) open--;
        else close++;
    }
    int ans = (open+1)/2 + (close+1)/2;
    return ans;
}