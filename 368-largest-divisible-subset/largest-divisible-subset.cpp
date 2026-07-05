class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int lastIndex = 0;
        int maxLen = 1;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prevInd = 0; prevInd < i; prevInd++) {
                if (arr[i] % arr[prevInd] == 0 && dp[i] < dp[prevInd] + 1) {
                    dp[i] = dp[prevInd] + 1;
                    hash[i] = prevInd;
                }
            }
            if (dp[i] > maxLen) {
                lastIndex = i;
                maxLen = dp[i];
            }
        }
        vector<int> ans;
        ans.push_back(arr[lastIndex]);
        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            ans.push_back(arr[lastIndex]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};