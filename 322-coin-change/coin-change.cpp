class Solution {
public:
    int func(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            else return 1e9;
        }
        
        if (dp[idx][amount] != -1) return dp[idx][amount];
        
        int not_take = func(idx - 1, coins, amount, dp);
        int take = 1e9;
        if (coins[idx] <= amount) {
            take = 1 + func(idx, coins, amount - coins[idx], dp);
        }
        
        return dp[idx][amount] = min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = func(n - 1, coins, amount, dp);
        if (ans >= 1e9) return -1;
        return ans;
    }
};