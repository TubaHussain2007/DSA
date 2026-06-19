class Solution {
public:
    vector<vector<int>>dir{{0 , -1} , {0 , 1} , {1 , 0} , {-1 , 0} , {-1 , -1} , {-1 , 1} , {1 , -1} , {1 , 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // int m = grid[0].size();
        if(n == 1 and grid[0][0] == 0)return 1;
        if(n == 1 and grid[0][0] == 1)return -1;
        if(grid[0][0] == 1 or grid[n-1][n-1] == 1)return -1;
        
        queue<pair<int , int>>q;
        q.push({0 , 0});
        vector<vector<bool>>vis(n , vector<bool>(n , 0));
        vis[0][0] = true;
        int ct = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto temp = q.front();
                q.pop();
                for(int i = 0 ; i < dir.size() ; i++){
                    int first = temp.first + dir[i][0];
                    int second = temp.second + dir[i][1];
                    if(first >= 0 and second >= 0 and first < n and second < n and !vis[first][second] and grid[first][second] == 0){
                        if(first == n-1 and  second == n-1){
                            return ct + 1;
                        }else{
                            vis[first][second] = true;
                            q.push({first , second});
                        }
                    }
                }
            }
            ct++;
        }
        
        return -1;
    }
};