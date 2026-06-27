class Solution {
public:
    const int mod = (int)1e9 + 7;
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            total_sum += nums[i];
        }
        if (abs(target) > total_sum || (total_sum - target) % 2 != 0)
            return 0;
        int sum = (total_sum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        if (nums[0] == 0)
            // 2 cases - pick and not pick
            dp[0][0] = 2;
        else
            // 1 case - not pick
            dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= sum)
            // 1 case - pick
            dp[0][nums[0]] = 1;
        for (int idx = 1; idx < n; idx++) {
            for (int k = 0; k <= sum; k++) {
                int notTake = dp[idx - 1][k];
                int take = 0;
                if (nums[idx] <= k)
                    take = dp[idx - 1][k - nums[idx]];
                dp[idx][k] = (notTake + take) % mod;
            }
        }
        return dp[n - 1][sum];
    }
};