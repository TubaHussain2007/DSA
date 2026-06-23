class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list for the graph
        // graph[u] stores pairs {v, w} for edges u -> v with weight w
        vector<vector<pair<int,int>>> graph(n + 1);
        for (auto &t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }

        // Initialize distance array with INT_MAX (infinity)
        // dist[i] stores the minimum time to reach node i
        vector<int> dist(n + 1, INT_MAX);
        // signal starts at node k at time 0
        dist[k] = 0; 

        // Min-heap priority queue to select node with smallest distance
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        // {distance, node}
        pq.push({0, k}); 

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // Skip if we already have a shorter distance
            if (d > dist[u]) continue;

            // Traverse all neighbors of current node
            for (auto &[v, w] : graph[u]) {
                // Update distance if shorter path is found
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // Find the maximum distance among all nodes
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};