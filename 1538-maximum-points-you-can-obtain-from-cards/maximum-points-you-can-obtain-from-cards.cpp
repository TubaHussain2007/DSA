class Solution {
public:
    int maxScore(vector<int>& cardScore, int k) {
        int n = cardScore.size();
      int lsum = 0, rsum = 0, maxSum = 0;
      for (int i = 0; i < k; i++) {
        lsum += cardScore[i];
        maxSum = lsum;
      }
      int rIdx = n-1;
      for(int i = k-1; i>=0; i--){
        lsum -= cardScore[i];
        rsum += cardScore[rIdx];
        rIdx--;
        maxSum = max(maxSum, lsum + rsum);
      }
      return maxSum;
    }
};