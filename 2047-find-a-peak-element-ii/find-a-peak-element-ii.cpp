class Solution {
public:
    int maxEle(vector<vector<int>>& mat, int n, int m, int col){
        int idx = -1;
        int max_ele = INT_MIN;
        for(int i =0; i<n; i++){
            if(mat[i][col] > max_ele){
                max_ele = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low =0, high = m-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            int row = maxEle(mat, n, m, mid);
            int left = mid-1 >=0 ? mat[row][mid-1] : -1;
            int right = mid+1 < m ? mat[row][mid+1] : -1;
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }else if(left > mat[row][mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return {-1, -1};
    }
};