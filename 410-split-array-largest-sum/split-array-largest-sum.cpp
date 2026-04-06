class Solution {
public:
    int countPartition(vector<int>& nums, int maxSum, int k){
        int partitions = 0;
        int sum =0;
        for(int i=0; i<nums.size(); i++){
            if(sum + nums[i] <= maxSum){
                sum += nums[i];
            }else{
                partitions++;
                sum = nums[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low<=high){
            int mid = low + (high -low)/2;
            if(countPartition(nums, mid, k) < k){
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return low;
    }
};