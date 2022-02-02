class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i=0; i<n; i++) {
            if(st.empty()) st.push(asteroids[i]);
            else if(st.top()>0 && asteroids[i]<0 && st.top()==-asteroids[i]) st.pop();
            else if (st.top()*asteroids[i]>0 || (st.top()<0 && asteroids[i]>0)) st.push(asteroids[i]);
            else {
                st.push(asteroids[i]);
                while(1) {
                    if(st.size()==1) break;
                    int first = st.top();
                    st.pop();
                    int second = st.top();
                    st.pop();
                    if(first<0 && second>0 && first==-second) break;
                    if(first*second>0 || (first>0 && second<0)) {
                        st.push(second);
                        st.push(first);
                        break;
                    }
                    if(abs(first)>abs(second)) st.push(first);
                    else st.push(second);
                }
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};