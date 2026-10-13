class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<int>>dist(m, vector<int>(n,1e9)); // here column  wala n ayaga

        priority_queue<pair<int, pair<int,int>>,
                        vector<pair<int, pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>>pq;

             dist[0][0]=0;
          pq.push({0,{0,0}});

        int dr[]= {-1,1,0,0};
        int dc[]={0,0,-1,1};

         while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int effort=it.first;
            int row=it.second.first;
            int col=it.second.second;

            if(row==m-1 && col==n-1){
                return effort;
            }

            if(effort>dist[row][col]){
                continue;
            }

            for(int i=0;i<4;i++){
                int nr= row+dr[i];
                int nc=col+dc[i];

                if(nr>=0 && nr<m &&nc>=0 && nc<n){
                    int diff=abs(heights[row][col]- heights[nr][nc]);
                
                
                int max_effort=max(effort,diff);

                if(max_effort<dist[nr][nc]){
                    dist[nr][nc]=max_effort;

                    pq.push({max_effort,{nr,nc}});
                }

                }
            }


         }   
         return 0;            

    }
};