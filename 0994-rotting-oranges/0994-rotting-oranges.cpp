class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<int,int>>q;
       int m=grid.size();
       int n=grid[0].size();
        int fresh=0;

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
        }
       }

       int minutes=0;

       while(!q.empty()){
        
            int size=q.size();
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;

                q.pop();

                if(row-1>=0&& grid[row-1][col]==1){
                    grid[row-1][col]=2;
                    fresh--;
                    q.push({row-1,col});
                }
                if(row+1<m&& grid[row+1][col]==1){   // here importannt
                    grid[row+1][col]=2;
                    fresh--;
                    q.push({row+1,col});
                }
               if(col-1>=0&& grid[row][col-1]==1){
                    grid[row][col-1]=2;
                    fresh--; 
                    q.push({row,col-1});
        }
           if(col+1<n&& grid[row][col+1]==1){       // here importannt
                    grid[row][col+1]=2;
                    fresh--; 
                    q.push({row,col+1});
        }
       
       }
       if(!q.empty()){
        minutes++;
       }
       }
            if(fresh>0){
                return -1;
            
       }
            return minutes;
    }
};