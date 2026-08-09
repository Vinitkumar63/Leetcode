class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int digit:num){
            while(!st.empty()&& k>0&& st.top()>digit ){
                st.pop();
                k--;
            }
            st.push(digit);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        // now remove the alphabet start with zero
        int i=0;
        while(i<ans.size()&& ans[i]=='0'){
            i++;
        }
        ans=ans.substr(i);

        if(ans.empty()){
         return "0"; // " " this is used in zero as we are using char
        }
        

        return ans;
    }
};