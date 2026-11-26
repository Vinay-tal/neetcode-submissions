class MinStack {
public:
    MinStack() {
        
        
    }
    vector<int> st;

    
    
    void push(int val) {
        st.push_back(val);
        
    }
    
    void pop() {
        if(!st.empty()){
            st.pop_back();}
            
        
    }
    
    int top() {
        if(!st.empty()){
            return st.back();
            }
        
        
    }
    
    int getMin() {
        set<int> s(st.begin(),st.end());
        return *s.begin();
        
    }
};
