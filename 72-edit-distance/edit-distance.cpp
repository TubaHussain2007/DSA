class Solution {
public:
    int minDistance(string start, string target) {
        int n = start.size();
        int m = target.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (start[i-1] == target[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {  // not match
                    // insert deletion replace
                    dp[i][j] =1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};