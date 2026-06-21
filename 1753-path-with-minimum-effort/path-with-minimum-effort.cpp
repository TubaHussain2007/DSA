class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // pq -> {diff, {row, col}}
        priority_queue< pair<int, pair<int, int>>, 
        vector< pair<int, pair<int, int>> >, 
        greater< pair<int, pair<int, int>> > > pq;
    
        int n = heights.size();
        int m = heights[0].size();

        //dist[][]
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0,0}});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == m-1) return diff;

            for(int i =0; i<4; i++){
                int newr = row + delRow[i];
                int newc = col + delCol[i];

                if(newr >=0 && newr<n &&
                   newc >=0 && newc <m){
                    int neweffort = max(abs(heights[row][col] - heights[newr][newc]), diff);
                    
                    if(neweffort < dist[newr][newc]){
                        dist[newr][newc] = neweffort;
                        pq.push({dist[newr][newc], {newr, newc}});
                    }
                }
            }
        }
        return -1;
    }
};