class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& arr, int i, int k) {
        if (i >= n) return 0;

        if (dp[i] != -1) return dp[i];

        int maxSum = 0;
        int subMax = 0;

        for (int len = 1; len <= k && i + len <= n; len++) {
            subMax = max(subMax, arr[i + len - 1]);
            int total = subMax * len + solve(arr, i + len, k);
            maxSum = max(maxSum, total);
        }

        return dp[i] = maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        dp.assign(n, -1);
        return solve(arr, 0, k);
    }
};