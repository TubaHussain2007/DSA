class Solution {
public:
    bool isMatched(char open, char close) {
        if((open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}')
        )
        return true;
    
        return false;
    }
    bool isValid(string str) {
        stack<int> st;
        for(int i=0; i < str.length(); i++) {
            if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
                st.push(str[i]);
            }
            else {
                if(st.empty()) return false;
                char ch = st.top();
                st.pop();

                if(!isMatched(ch, str[i])) return false;
            }
        }
        return st.empty();
    }
};