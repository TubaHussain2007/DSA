class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        if (str.empty()) return "";
        sort(str.begin(), str.end());
        string first = str[0];
        string last = str[str.size() - 1];
        int min_len = min(first.size(), last.size());
        string res = "";
        for (int i = 0; i < min_len; i++) {
            if (first[i] != last[i]) return res;
            res += first[i];
        }
        return res;
    }
};