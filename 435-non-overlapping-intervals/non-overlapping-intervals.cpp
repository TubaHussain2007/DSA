class Solution {
public:
    static bool comparator(vector<int>& val1, vector<int>& val2) {
        return val1[1] < val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& Intervals) {
        int n = Intervals.size();
        sort(Intervals.begin(), Intervals.end(), comparator);
        int last_endTime = Intervals[0][1];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (Intervals[i][0] >= last_endTime) {
                cnt++;
                last_endTime = Intervals[i][1];
            }
        }
        return n - cnt;
    }
};