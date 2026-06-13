class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int newColor, vector<vector<int>>& ans, int iniColor) {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(image, nrow, ncol, newColor, ans, iniColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(image, sr, sc, color, ans, iniColor);
        return ans;
    }
};