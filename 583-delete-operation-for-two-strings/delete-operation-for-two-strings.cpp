class Solution {
private:
    int lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int idx1 = 1; idx1 <= n; idx1++) {
            for (int idx2 = 1; idx2 <= m; idx2++) {
                if (str1[idx1 - 1] == str2[idx2 - 1]) {
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                } else {
                    dp[idx1][idx2] =
                        max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
                }
            }
        }
        return dp[n][m];
    }

public:
    int minDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int total_operations = (n + m) - 2 * lcs(str1, str2);
        return total_operations;
    }
};