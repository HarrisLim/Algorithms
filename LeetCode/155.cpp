class MinStack {
public:
    vector<int> stk;
    int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push_back(val);
        mini = min(mini, val);
    }
    
    void pop() {
        stk.pop_back();
        mini = INT_MAX;
        for(int n : stk)
        {
            mini = min(mini, n);
        }
    }
    
    int top() {
        return stk[stk.size()-1];
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
