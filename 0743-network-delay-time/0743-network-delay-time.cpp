
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        // Build the directed graph
        for (auto &e : times) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // Min-heap: {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated entries
            if (d > dist[node]) continue;

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;

        // Find the maximum shortest distance
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
