class Solution {
public:
void dfs(int row, int col,vector<vector<int>>& grid){
    if(row<0|| row>=grid.size()
              || col<0 || col>=grid[0].size()){
        return ;
    }
        if(grid[row][col]==0){
            return;
        }
        grid[row][col]=0;

        // up
        dfs(row-1,col,grid);
        // down
        dfs(row+1,col,grid);
        // left
        dfs(row,col-1,grid);
        // right
        dfs(row,col+1,grid);
}
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
    // rows from top to bottom
        for(int j=0;j<n;j++){
            if(grid[0][j]==1){
                dfs(0,j,grid);
            }
            if(grid[m-1][j]==1){
                dfs(m-1,j,grid);
            }
        }
        // now from col first to last
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid);
            }
            if(grid[i][n-1]==1){
                dfs(i,n-1,grid);
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        count++;
                    }
                }
        }
        return count;
    }
};