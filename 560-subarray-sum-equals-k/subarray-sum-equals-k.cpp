class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefSum  = 0, cnt =0;
        for(int i =0; i<n; i++){
            prefSum += nums[i];
            int remove = prefSum - k;
            cnt += mp[remove];
            mp[prefSum] +=1;
        }
        return cnt;
    }
};