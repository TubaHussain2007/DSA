class Solution {
public:
int fnc(string& s1, string& s2, int i, int j, vector<vector<int>> &dp){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j] != -1) return dp[i][j];
    //match
    if(s1[i] == s2[j]){
         return dp[i][j] =  fnc(s1, s2, i-1, j-1, dp);
    }else { // not match
        //insert deletion replace
        return dp[i][j] =  1 + min(fnc(s1, s2, i, j-1, dp),
                   min(fnc(s1, s2, i-1, j, dp), 
                   fnc(s1, s2, i-1, j-1, dp)));
    }
  }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fnc(word1, word2, n-1, m-1, dp);
    }
};