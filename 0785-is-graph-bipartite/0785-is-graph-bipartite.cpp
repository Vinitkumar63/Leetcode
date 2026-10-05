class Solution {
public:
bool dfs(int node,vector<vector<int>>& graph ,vector<int>& color){
    for(auto next:graph[node]){
        if(color[next]==-1){
            color[next]=1-color[node];

            if(!dfs(next,graph,color)){
                return false;
            }
        }
         else if(color[node]==color[next]){
            return false;
       
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int >color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(i,graph,color)){
                    return false;
                }
            }
        }
        return true;
    }
};