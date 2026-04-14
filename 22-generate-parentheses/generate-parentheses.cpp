class Solution {
public:
    void fnc(int open, int close, string s, int n, vector<string>& ans){
        if((open+close) == 2*n && (open == close)){
            ans.push_back(s);
            return;
        }
        if(open<n){
            fnc(open+1, close, s + '(', n, ans);
        }
        if(close < open){
            fnc(open, close+1, s + ')', n, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fnc(0, 0, "", n, ans);
        return ans;
    }
};