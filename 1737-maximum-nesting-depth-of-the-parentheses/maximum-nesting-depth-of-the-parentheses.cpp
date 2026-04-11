class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int cnt =0, maxCnt =0;
        for(int i =0; i<n; i++){
            if(s[i] == '(') cnt++;
            if(s[i] == ')'){
                maxCnt = max(maxCnt, cnt);
                cnt--;
            }
        }
        return maxCnt;
    }
};