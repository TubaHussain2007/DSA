class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        int profit = 0;
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 0) {
                        profit = max((-1) * arr[idx] + dp[idx + 1][1][cap],
                                     0 + dp[idx + 1][0][cap]);
                    }
                    // sell time
                    if (buy == 1) {
                        profit = max((arr[idx] + dp[idx + 1][0][cap - 1]),
                                     0 + dp[idx + 1][1][cap]);
                    }
                    dp[idx][buy][cap] = profit;
                }
            }
        }
        return dp[0][0][2];
    }
};