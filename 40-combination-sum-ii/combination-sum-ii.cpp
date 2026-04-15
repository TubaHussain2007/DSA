class Solution {
public:
    void fnc(int idx, vector<int>& candidates, int sum, vector<vector<int>>& ans, vector<int>& arr){
        int n = candidates.size();
        if(sum == 0){
            ans.push_back(arr);
            return;
        }
        if(sum < 0 || idx == n) return;
        arr.push_back(candidates[idx]);
        fnc(idx+1, candidates, sum -candidates[idx], ans, arr);
        arr.pop_back();
        for(int j = idx+1; j<n; j++){
            if(candidates[j] != candidates[j-1]){
                fnc(j, candidates, sum, ans, arr);
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        fnc(0, candidates, target, ans, arr);
        return ans;
    }
};