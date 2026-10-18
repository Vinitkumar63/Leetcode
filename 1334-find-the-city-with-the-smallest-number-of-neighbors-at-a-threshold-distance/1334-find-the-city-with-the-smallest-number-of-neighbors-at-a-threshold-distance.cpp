
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        // Distance from a city to itself is 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Build the graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        // Floyd-Warshall algorithm
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] != 1e9 &&
                        dist[via][j] != 1e9) {

                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][via] + dist[via][j]
                        );
                    }
                }
            }
        }

        int city = -1;
        int minCount = INT_MAX;

        // Count reachable cities for each city
        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            // <= ensures ties select the greatest city index
            if (count <= minCount) {
                minCount = count;
                city = i;
            }
        }

        return city;
    }
};
