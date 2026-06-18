class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> adjRev[V];
        vector<int> indegree(V, 0);

        // Create reverse graph and calculate indegree
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        // Terminal nodes (outdegree = 0 in original graph)
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safeNode;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safeNode.push_back(node);

            for (auto it : adjRev[node]) {
                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safeNode.begin(), safeNode.end());

        return safeNode;
    }
};