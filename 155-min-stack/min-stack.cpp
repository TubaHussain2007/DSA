class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {}

    void push(int val) {
        long long v = val;

        if (st.empty()) {
            st.push(v);
            mini = v;
        } 
        else if (v > mini) {
            st.push(v);
        } 
        else {
            st.push(2 * v - mini);  // safe now
            mini = v;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        if (x < mini) {
            mini = 2 * mini - x;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long x = st.top();
        if (x > mini) return (int)x;

        return (int)mini;
    }

    int getMin() {
        return (int)mini;
    }
};