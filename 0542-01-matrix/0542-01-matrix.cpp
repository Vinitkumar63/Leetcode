class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else{
                    mat[i][j]=-1; // means we are not visited 
                }
            }
        }
        while(!q.empty()){
            int size=q.size();

                        for(int i=0;i<size;i++){

            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
                // up
                if(row-1>=0 && mat[row-1][col]==-1){
                    mat[row-1][col]=mat[row][col]+1;
                    q.push({row-1,col});
                }
                // down
                if(row+1<m && mat[row+1][col]==-1 ){
                    mat[row+1][col]=mat[row][col]+1;

                    q.push({row+1,col});
                }
                // left
                if(col-1>=0 && mat[row][col-1]==-1){
                    mat[row][col-1]=mat[row][col]+1;

                    q.push({row,col-1});
                }

                // right
                if(col+1<n && mat[row][col+1]==-1){
                    mat[row][col+1]=mat[row][col]+1;

                    q.push({row,col+1});
                }
            }
        }
        return mat;
    }
};