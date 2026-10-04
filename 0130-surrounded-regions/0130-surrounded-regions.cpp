class Solution {
public:
void dfs(int row,int col,vector<vector<char>>& board){
    
    // boundary check
    if(row<0 || row>=board.size()
      || col<0 || col>=board[0].size()){
        return;
      }

    if(board[row][col]!='O'){
        return;
    }
    board[row][col]='#';

    // up
    dfs(row-1,col,board);

    // down
    dfs(row+1,col,board);

    // left
    dfs(row,col-1,board);

    // right
    dfs(row,col+1,board);

}
    void solve(vector<vector<char>>& board) {
    int m=board.size();
    int n=board[0].size();

    for(int j=0;j<n;j++){
        if(board[0][j]=='O'){
            dfs(0,j,board);
        }
        if(board[m-1][j]=='O'){
            dfs(m-1,j,board);
        }
    }

    for(int i=0;i<m;i++){
        if(board[i][0]=='O'){
            dfs(i,0,board);
        }
        if(board[i][n-1]=='O'){
            dfs(i,n-1,board);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='O'){
                board[i][j]='X';
            }
            else if(board[i][j]=='#'){
                board[i][j]='O';
            }
        }
    }
    }
};