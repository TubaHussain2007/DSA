class Solution {
public:
    int cntSubarraysWithSumLessK(vector<int>& nums, int K) {
        int n = nums.size();
        int l = 0, r = 0, cnt = 0, sum = 0;
        if (K < 0)
            return 0;
        while (r < n) {
            sum = sum + nums[r] % 2;
            while (sum > K) {
                sum = sum - nums[l] % 2;
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return cntSubarraysWithSumLessK(nums, k) -
               cntSubarraysWithSumLessK(nums, k - 1);
    }
};