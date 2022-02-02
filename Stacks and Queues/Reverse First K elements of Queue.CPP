queue<int> modifyQueue(queue<int> q, int k) {
    int n = q.size();
    stack<int> st;
    for(int i=0; i<k; i++) {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()) {
        q.push(st.top()); 
        st.pop();
    }
    for(int i=0; i<n-k; i++) {
        q.push(q.front());
        q.pop();
    }
    return q;
}