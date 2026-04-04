class Solution {
public:
    int search(vector<int> &arr, int k) {
       int n= arr.size(); 
       int low =0, high = n-1;
       while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] == k){
            return mid;
        }
        //left half sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= k && k <= arr[mid]){
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }//right half sorted
        else{
            if(arr[mid] <= k && k <= arr[high]){
                low = mid + 1;
            }else{
                high = mid-1;
            }
        }
       }
       return -1;;
    }
};