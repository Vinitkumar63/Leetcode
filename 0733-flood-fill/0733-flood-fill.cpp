class Solution {
public:
void dfs(int row,int col,vector<vector<int>>& image, int original_color, int color){
    if(row<0|| row>=image.size()
           || col<0 || col>=image[0].size()){
        return;
    }
    if(image[row][col]!=original_color){
        return;
    }
   image[row][col]=color;
   // up
   dfs(row+1,col,image,original_color,color);

   // down
   dfs(row-1,col,image,original_color,color);

   // left
   dfs(row,col-1,image,original_color,color);

   // right
   dfs(row,col+1,image,original_color,color);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original_color=image[sr][sc];

        if(original_color==color){
            return image;
        }
        dfs(sr,sc,image,original_color,color);
        return image;
    }
};