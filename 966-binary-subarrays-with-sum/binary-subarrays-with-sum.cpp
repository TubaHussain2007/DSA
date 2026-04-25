class Solution {
    private:
    int cntSubarraysWithSumLessK(vector<int>& arr, int K) {
        int n = arr.size();
        int l=0, r=0, cnt=0, sum =0;
        if(K < 0) return 0;
        while(r<n){
            sum += arr[r];
            while(sum > K){
                sum -= arr[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& arr, int K) {
       return cntSubarraysWithSumLessK(arr, K) - cntSubarraysWithSumLessK(arr, K-1);
    }
};