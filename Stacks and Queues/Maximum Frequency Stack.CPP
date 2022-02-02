class FreqStack {
private:
    int mxFreq;
    map<int, stack<int>> freqSt;
    map<int, int> freqMp;
public:
    FreqStack() {
        mxFreq = 0;
    }
    
    void push(int val) {
        mxFreq = max(mxFreq, ++freqMp[val]);
        freqSt[freqMp[val]].push(val);
    }
    
    int pop() {
        int popped_element = freqSt[mxFreq].top();
        freqMp[popped_element]--;
        freqSt[mxFreq].pop();
        if(freqSt[mxFreq].empty()) mxFreq--;
        return popped_element;
    }
};