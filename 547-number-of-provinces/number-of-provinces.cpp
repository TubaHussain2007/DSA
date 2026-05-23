class Solution {
public:

    void dfs(int node, vector<int> adjList[], vector<int>& vis) {

        vis[node] = 1;

        for(auto it : adjList[node]) {

            if(!vis[it]) {
                dfs(it, adjList, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {

        int V = adj.size();

        vector<int> adjList[V];

        for(int i = 0; i < V; i++) {

            for(int j = 0; j < V; j++) {

                if(adj[i][j] == 1 && i != j) {

                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);

        int cnt = 0;

        for(int i = 0; i < V; i++) {

            if(!vis[i]) {

                cnt++;

                dfs(i, adjList, vis);
            }
        }

        return cnt;
    }
};