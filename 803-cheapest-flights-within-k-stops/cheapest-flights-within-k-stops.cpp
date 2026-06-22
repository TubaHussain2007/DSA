class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        //make graph
        vector<pair<int, int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> cost(n, 1e9);
        cost[src] = 0;

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cos = q.front().second.second;
            q.pop();

            if(stops > K) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;

                if(cos + edgeWt < cost[adjNode] && stops <= K){
                    cost[adjNode] = cos + edgeWt;
                    q.push({stops + 1, {adjNode, cost[adjNode]}});
                }
            }
        } 
        if(cost[dst] == 1e9) return -1;
        return cost[dst];
    }
};