class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector(n, 0));
        for (int j = 0; j < n; j++) {
            dp[n-1][j] = triangle[n - 1][j];
        }
        for (int row = n-2; row>=0; row--) {
            for (int col = row; col>=0; col--) {
                int up = dp[row + 1][col];
                int up_left = dp[row + 1][col + 1];
                dp[row][col] = min(up, up_left) + triangle[row][col];
            }
        }
        return dp[0][0];
    }
};