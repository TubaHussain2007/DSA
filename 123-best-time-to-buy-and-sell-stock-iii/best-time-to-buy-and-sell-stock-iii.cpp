class Solution {
public:
    int fnc(int idx, vector<int>& arr, int buy, int cap,
            vector<vector<vector<int>>>& dp) {
        int profit = 0;
        if (cap == 0 || idx == arr.size())
            return 0;
        if (dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];
        // buy time
        if (buy == 0) {
            profit = max(((-1) * arr[idx] + fnc(idx + 1, arr, 1, cap, dp)),
                         0 + fnc(idx + 1, arr, 0, cap, dp));
        }
        // sell time
        if (buy == 1) {
            profit = max((arr[idx] + fnc(idx + 1, arr, 0, cap - 1, dp)),
                         0 + fnc(idx + 1, arr, 1, cap, dp));
        }
        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        return fnc(0, arr, 0, 2, dp);
    }
};