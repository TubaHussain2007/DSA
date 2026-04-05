class Solution {
public:
    int maxEle(vector<int>& nums) {
        int max_ele = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            max_ele = max(max_ele, nums[i]);
        }
        return max_ele;
    }
    long long totalSum(vector<int>& nums, int divisor){
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += ceil((double)nums[i]/(double)divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = maxEle(nums);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long total_sum = totalSum(nums, mid);
            if (total_sum <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};