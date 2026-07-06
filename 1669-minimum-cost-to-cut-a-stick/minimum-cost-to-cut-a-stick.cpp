class Solution {
private:
    int fnc(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        int mini = INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];
        for (int idx = i; idx <= j; idx++) {
            int ans = cuts[j + 1] - cuts[i - 1] + fnc(i, idx - 1, cuts, dp) +
                      fnc(idx + 1, j, cuts, dp);
            mini = min(mini, ans);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return fnc(1, c, cuts, dp);
    }
};