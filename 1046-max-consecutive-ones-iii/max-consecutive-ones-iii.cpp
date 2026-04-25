class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0, r =0;
        int zeroes =0, maxLen =0, len =0;
        while(r<n){
            if(nums[r] == 0) zeroes++;
            if(zeroes >k){
                if(nums[l] == 0){
                    zeroes--;
                }
                l++;
            }
            if(zeroes <= k){
                len = r-l+1;
                maxLen = max(maxLen, len);
            }
            r++;
        }
        return maxLen;
    }
};