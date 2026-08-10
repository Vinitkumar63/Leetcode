class Solution {
public:
    int largestRectangleArea(vector<int>& heigths) {
        int ans=0;
        int n= heigths.size();
        stack<int>st;
        for(int i=0;i<=n;i++){  // here i ko ham i< and = tak la gaya
        int curr=0;
            if(i==n)
            curr=0;// menas right ma koi box nahi ha to find the rectangle
            else
            curr=heigths[i];

            while(!st.empty()&& heigths[st.top()]>curr){
                int height= heigths[st.top()];
                st.pop();
                
                int width;
                if(st.empty())
                width=i;
                else
                width=i-st.top()-1; // ya tarika ha width ka

                ans=max(ans,height*width);
            }
            st.push(i);
        }
        return ans;
    }
};