class Solution {
public:
    bool isMatch(string str, string pat) {
        int n = str.size();
        int m = pat.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
        dp[0][0] = true;
        for (int i = 1; i<=n; i++) {
            dp[i][0] = false;
        }
        for (int j = 1; j<=m; j++) {
            int flag = true;
            for (int t = 1; t <= j; t++) {
                if (pat[t-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str[i-1] == pat[j-1] || pat[j-1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pat[j-1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};