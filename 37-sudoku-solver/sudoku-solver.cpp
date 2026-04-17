class Solution {
   public:
    void solveSudoku(vector<vector<char> >& grid) {
        fnc(grid);
    }
    private:
    bool fnc(vector<vector<char> >& grid) {
        int n = 9;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (rulesMet(grid, i, j, digit)) {
                            grid[i][j] = digit;
                            if (fnc(grid))
                                return true;
                            else
                                grid[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool rulesMet(vector<vector<char> >& grid, int row, int col, char digit){
        int startRow = (row/3) * 3;
        int startCol = (col/3) * 3;
        for(int i = 0; i<9; i++){
            //rule 1+rule2
            if (grid[row][i] == digit || grid[i][col] == digit) {
                return false;  
            }
            // rule 3
            if(grid[startRow + i/3][startCol + i%3] == digit){
                return false;
            }
        }
        return true;
    }
};