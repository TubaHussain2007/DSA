class Solution {
public:
    int fnc(int idx, vector<int>& arr, int buy, int fee,
            vector<vector<int>>& dp) {
        if (idx == arr.size()) {
            return 0;
        }

        if (dp[idx][buy] != -1)
            return dp[idx][buy];

        int profit = 0;

        // Buy
        if (buy == 0) {
            profit = max(-arr[idx] + fnc(idx + 1, arr, 1, fee, dp),
                         fnc(idx + 1, arr, 0, fee, dp));
        }
        // Sell
        else {
            profit = max(arr[idx] - fee + fnc(idx + 1, arr, 0, fee, dp),
                         fnc(idx + 1, arr, 1, fee, dp));
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& arr, int fee) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return fnc(0, arr, 0, fee, dp);
    }
};