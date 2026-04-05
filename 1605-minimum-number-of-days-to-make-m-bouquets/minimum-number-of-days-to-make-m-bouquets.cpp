class Solution {
public:
    int minEle(vector<int>& nums) {
        int min_ele = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            min_ele = min(min_ele, nums[i]);
        }
        return min_ele;
    }

    int maxEle(vector<int>& nums) {
        int max_ele = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            max_ele = max(max_ele, nums[i]);
        }
        return max_ele;
    }

    int numberOfB(int n, vector<int>& nums, int day, int k) {
        int noOfB = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= day) {
                cnt++;
            } else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB;
    }

    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();

        if(n< (long long)m * k) return -1; 

        int low = minEle(nums);
        int high = maxEle(nums);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int noOfB = numberOfB(n, nums, mid, k);

            if (noOfB >= m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};