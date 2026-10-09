class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }

        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        // mark 0,0 as visited
            grid[0][0]=1;

            while(!q.empty()){
                auto front=q.front();
                q.pop();

                int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
                
                int dist=front.first;
                int row=front.second.first;
                int col=front.second.second;

                // when reach to final destination
                if(row==n-1 && col==n-1){
                        return dist;
                }

                for(int i=0;i<8;i++){
                    int newrow=row+dr[i];
                    int newcol=col+dc[i];

                    if(newrow>=0&& newrow<n && newcol>=0 && newcol<n && grid[newrow][newcol]==0){
                        q.push({dist+1,{newrow,newcol}});

                        grid[newrow][newcol]=1;
                    }
                }
            }
        return -1;
    }
};