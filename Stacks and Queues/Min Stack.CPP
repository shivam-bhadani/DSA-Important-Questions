// Using two stacks

class MinStack {
public:
    stack<int> st1, st2;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        if(st2.empty() || st2.top()>=val) {
            st2.push(val);
        } 
    }
    
    void pop() {
        if(st1.top()==st2.top()) {
            st2.pop();
        }
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};


// Using one stack

class MinStack {
private:
    stack<long long> st;
    long long curr_min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            curr_min = val;
            st.push(val);
        }
        else if(curr_min<=val) {
            st.push(val);
        }
        else {
            long long temp = 2*1LL*val - curr_min;
            st.push(temp);
            curr_min = val;
        }
    }
    
    void pop() {
        if(st.top()>=curr_min) {
            st.pop();
        }
        else {
            curr_min = 2*1LL*curr_min - st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top()>=curr_min) {
            return st.top();
        }
        else {
            return curr_min;
        }
    }
    
    int getMin() {
        return curr_min;
    }
};