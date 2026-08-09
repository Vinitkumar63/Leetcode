class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int asteroid:asteroids){
            bool destroyed= false;// beacuse we assume ki collision nahi hoya ha
            while(!st.empty()&&st.top()>0 && asteroid<0){
                if(st.top()<-asteroid)
                // here the stack asteroids is smaller so st hi remove hoga
                st.pop();
                else if(st.top()==-asteroid){
                    // here both are same so both are pop up
                    st.pop();
                    destroyed=true;
                    break;
                }
                else{
                    // here the asteroid is smaller
                    destroyed=true; /// this is for the asteroids
                    break;
                }
            }
            if(!destroyed){
                st.push(asteroid);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};