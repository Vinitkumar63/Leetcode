class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>freq(3,0);
        
        int left=0;
        int ans=0;

        for(int right=0;right<s.size();right++){
            freq[s[right]-'a']++;
            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                ans+=s.size()-right; // important
                freq[s[left]-'a']--;
                left++;
            }
        }
            return ans;
        
    }
};