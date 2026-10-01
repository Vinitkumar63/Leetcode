class Solution {
public:
void dfs(int node,vector<vector<int>>& isConnected , vector<int>& visited){
    visited[node]=1;
    for(int j=0;j<isConnected.size();j++){
        if(!visited[j] &&  isConnected[node][j]==1){ //  isconnected[node][j] it means they are connected adjacent
            dfs(j,isConnected,visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,isConnected,visited);
            }
        }
        return count;
    }
};