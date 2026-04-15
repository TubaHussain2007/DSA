class Solution {
public:
    void fnc(int idx, vector<int>& nums, vector<vector<int>>& ans,
             vector<int>& arr) {
        int n = nums.size();
        if (idx == n) {
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[idx]);
        fnc(idx + 1, nums, ans, arr);
        arr.pop_back();
        for (int j = idx + 1; j < n; j++) {
            if (nums[j] != nums[idx]) {
                fnc(j, nums, ans, arr);
                return;
            }
        }
        fnc(n, nums, ans, arr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(), nums.end());
        fnc(0, nums, ans, arr);
        return ans;
    }
};