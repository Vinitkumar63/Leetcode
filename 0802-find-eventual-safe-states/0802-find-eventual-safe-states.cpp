class Solution {
public:
bool dfs(int node, vector<vector<int>>& graph,vector<int> & state){
    if(state[node]==1){
        return true;
    }
    if(state[node]==2){
        return false;
    }
    state[node]=1;

    for(auto next:graph[node]){

        if(dfs(next,graph,state)){
            return true;
        }
    }
    state[node]=2;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>state(n,0);

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(!dfs(i,graph,state)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};