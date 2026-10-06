class Solution {
public:
bool dfs(int node, vector<vector<int>>& adj, vector<int>& pathvisited, vector<int>& visited, vector<int>& ans){
    if(pathvisited[node]){
        return true; // ther is cycle
    }
    if(visited[node]){
        return false;
    }
    // mark them visited;
    visited[node]=1;
    pathvisited[node]=1;

    for(auto next:adj[node]){
        if(dfs(next,adj,pathvisited,visited,ans)){
            return true;
        }
    }
    pathvisited[node]=0;
    ans.push_back(node);

    return false;
    
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

       

        for(auto p:prerequisites){
            int course=p[0];
            int pre=p[1];

            adj[pre].push_back(course);
        }
        vector<int>visited(numCourses,0);
        vector<int>pathvisited(numCourses,0);
         vector<int> ans;

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adj,pathvisited,visited,ans)){
                    return {}; // here we return empty
                }
            }
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};