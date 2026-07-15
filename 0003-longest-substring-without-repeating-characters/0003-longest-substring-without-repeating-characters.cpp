class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int left=0;
        int max_length=0;
        for(int right=0;right<s.size();right++){    // here if you right here as st.size so as the st is an empty so we cannot consider it
            while(st.count(s[right])){
                // count right;
                // now for duplicicies remove left
                st.erase(s[left]);
                left++;
            }
            // but insert right part
            st.insert(s[right]);
            max_length=max(max_length,right-left+1);
        
        }
        return max_length;
        
    }
};