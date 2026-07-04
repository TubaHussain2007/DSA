class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        int profit = 0;
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for (int idx = n-1; idx>=0; idx--) {
            for (int buy = 0; buy<=1; buy++) {
                if (buy == 0) {
                    profit = max(((-1) * arr[idx] + dp[idx + 1][1]), 0 + dp[idx + 1][0]);
                }
                // sell time
                if (buy == 1) {
                    profit = max((arr[idx] + dp[idx + 1][0]), 0 + dp[idx + 1][1]);
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][0];
    }
};