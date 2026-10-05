class Solution {
public:
bool dfs(int node, vector<vector<int>>&adj, vector<int>& visited, vector<int>& pathvisited){
    visited[node]=1;

    pathvisited[node]=1;

for(auto next:adj[node]){
        if(!visited[next]){
           if(!dfs(next,adj,visited,pathvisited)){
            return false;
           }
           }
           else if(pathvisited[next]){
            return false;
}
}
pathvisited[node]=0;

return true;

}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto p:prerequisites){
            int course=p[0];
            int pre=p[1];

            adj[pre].push_back(course);
        }
        vector<int>visited(numCourses,0);
        vector<int>pathvisited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(!dfs(i,adj,visited,pathvisited)){
                    return false;
                }
            }
        }
        return true;
    }
};