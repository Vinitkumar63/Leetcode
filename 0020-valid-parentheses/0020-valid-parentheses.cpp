class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s){
            // for closing bracket
            if(ch=='('|| ch=='{'|| ch=='[')
            st.push(ch);
            else{
                // if it is a closing bracket
                if(st.empty())
                return false;
                if(ch==')'&& st.top()!='(')
                return false;
                if(ch=='}'&& st.top()!='{')
                return false;
                if(ch==']'&& st.top()!='[')
                return false;

                st.pop();
            }
        }
        return st.empty(); // this is important ki phela hamana check kiya ki st.empy ha ya nahi and here we print it
    }
};