class Solution {
public:
    void fnc(int idx, string s, string combo[], string digits,
             vector<string>& ans) {
        if (idx == digits.size()) {
            ans.push_back(s);
            return;
        }
        int num = digits[idx] - '0';
        for (int i = 0; i < combo[num].size(); i++) {
            fnc(idx + 1, s + combo[num][i], combo, digits, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        string combo[] = {"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        fnc(0, "", combo, digits, ans);
        return ans;
    }
};