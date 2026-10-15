class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto &flight:flights){
            int u=flight[0];
            int v=flight[1];
            int price=flight[2];

            adj[u].push_back({v,price});
        }

        vector<int>dist(n,INT_MAX);

            dist[src]=0;

            queue<pair<int,pair<int,int>>>q;

            q.push({0,{src,0}});

            while(!q.empty()){
                auto[stop,nodecast]=q.front();
                q.pop();

                int node=nodecast.first;
                int cost=nodecast.second;

                if(stop>k){  ///  when stop jyada hoga 
                    continue;
                }

                for(auto it: adj[node]){
                    int adjnode=it.first;
                    int price=it.second;

                    if(cost+price<dist[adjnode]){
                        dist[adjnode]=cost+price;
                        q.push({stop+1,{adjnode,cost+price}});
                    }
                }
            }
            return dist[dst]==INT_MAX?-1:dist[dst];

    }
};