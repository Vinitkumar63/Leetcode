class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod= 1e9+7;

        vector<vector<pair<int,int>>>adj(n);

        for(auto & road:roads){
            int u=road[0];
            int v=road[1];
            int time=road[2];

            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }

        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);

        priority_queue<pair<long long,int>,
                   vector<pair<long long,int >>,
                            greater<pair<long long ,int>>>q;

                            dist[0]=0;
                            ways[0]=1;
                            q.push({0,0});

         while(!q.empty()){
            auto[time,node]=q.top();
                    q.pop();

                    if(time>dist[node]){
                        continue;
                    }

                    for(auto it:adj[node]){    // upper hamna phela adj[u].push_back({v,time}) kiya tha so wahi order karna padaga
                        int next_node=it.first;
                        int next_time=it.second;

                        long long new_time=time+next_time;

                        if(new_time<dist[next_node]){
                            dist[next_node]=new_time;
                            ways[next_node]=ways[node];

                            q.push({new_time,next_node});
                        }

                        else if(new_time==dist[next_node]){
                            ways[next_node]= (ways[next_node]+(long long)ways[node])%mod;
                        }
                    }
         }
         return ways[n-1];
    }
};