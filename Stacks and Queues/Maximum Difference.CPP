class Solution{
    public:
    int findMaxDiff(int A[], int n)
    {
        int *nsr = new int[n];
        int *nsl = new int[n];
        nextSmallerRight(A, n, nsr);
        nextSmallerLeft(A, n, nsl);
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, abs(nsr[i]-nsl[i]));
        }
        return ans;
    }
    void nextSmallerRight(int arr[], int n, int nsr[]) {
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            if(st.empty()) nsr[i] = 0;
            else if(st.top()<arr[i]) nsr[i] = st.top();
            else {
                while(!st.empty() && st.top()>=arr[i]) st.pop();
                if(st.empty()) nsr[i] = 0;
                else nsr[i] = st.top();
            }
            st.push(arr[i]);
        }
    }
    void nextSmallerLeft(int arr[], int n, int nsl[]) {
        stack<int> st;
        for(int i=0; i<n; i++) {
            if(st.empty()) nsl[i] = 0;
            else if(st.top()<arr[i]) nsl[i] = st.top();
            else {
                while(!st.empty() && st.top()>=arr[i]) st.pop();
                if(st.empty()) nsl[i] = 0;
                else nsl[i] = st.top();
            }
            st.push(arr[i]);
        }
    }
};