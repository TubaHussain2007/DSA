class Solution {
public:
int maxEle(vector<int>& nums) {
        int max_ele = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            max_ele = max(max_ele, nums[i]);
        }
        return max_ele;
    }
int total_Sum(vector<int>& weights){
    int sum=0;
    for(int i =0; i<weights.size(); i++){
        sum += weights[i];
    }
    return sum;
}
    int total_days(vector<int>& weights, int limit){
        int day =1, sum =0;
        for(int i =0; i<weights.size(); i++){
            if(sum + weights[i]<=limit){
                sum += weights[i];
            }else{
                day++;
                sum=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low =maxEle(weights) , high = total_Sum(weights);
        while(low<= high){
            int mid = low + (high-low)/2;
            if(total_days(weights, mid) <= days){
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};