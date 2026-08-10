class Solution {
public:
int maximumrectangle_area(vector<int>& h){
    int ans=0;
    stack<int>st;
    int n=h.size();
    for(int i=0;i<=n;i++){
        // its check for i<=n so = to ko check kar raha ha
        int curr=0;
        if(i==n)
        curr=0;
        else
        curr=h[i];

        while(!st.empty()&& h[st.top()]>curr){
            int height= h[st.top()];
            st.pop();

            int width;
            if(st.empty())
            width=i;
            else
            width=i-st.top()-1; // ya dhayan kar lo

            ans= max(ans,height*width);
        }
        st.push(i);
    }
    return ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows= matrix.size();
        int column= matrix[0].size();
        int ans=0;
         vector<int>h(column,0); // hamna column ko zeo rakh liya like[0,0,0,0,0]
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<column;j++){
                if(matrix[i][j]=='1')
                h[j]++;
                else
                h[j]=0;
            }
            ans=max(ans,maximumrectangle_area(h)); // yaha bracket ma h likha important ha
        }
        return ans;

    }
};