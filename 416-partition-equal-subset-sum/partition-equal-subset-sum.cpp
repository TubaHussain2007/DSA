class Solution {
public:
    bool isSubsetSum(vector<int> arr, int k) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (arr[0] <= k)
            dp[0][arr[0]] = true;
        for (int idx = 1; idx < n; idx++) {
            for (int target = 1; target <= k; target++) {
                bool notTake = dp[idx - 1][target];
                bool take = false;
                if (target >= arr[idx])
                    take = dp[idx - 1][target - arr[idx]];
                dp[idx][target] = (notTake || take);
            }
        }
        return dp[n - 1][k];
    }
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        if (sum % 2)
            return false;
        int target = sum / 2;
        return (isSubsetSum(arr, target));
    }
};