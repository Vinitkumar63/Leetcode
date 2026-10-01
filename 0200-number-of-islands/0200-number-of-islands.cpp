const static auto fast_io = [](){ cin.tie(nullptr); ios::sync_with_stdio(false); return 0; }();
class Solution {  
public:
void dfs(int row,int col,vector<vector<char>>& grid){
    // set boundary
    if(row<0 || row>=grid.size()
            || col<0 || col>=grid[0].size()){
                return ;
            }
    // if it is water
    if(grid[row][col]=='0'){
        return;
    }
    // change all land to 0
    grid[row][col]='0';

    // move up
    dfs(row-1,col,grid);
    // move down
    dfs(row+1,col,grid);
    // move left
    dfs(row,col-1,grid);
    // move right
    dfs(row,col+1,grid);
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;

                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};