class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);

        for(char ch:word){
            freq[ch-'a']++;
        }
        // sort them in decending order
        sort(freq.begin(),freq.end(),greater<int>());

        int ans=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0){
                break;
            }
            int pushes =i/8+1;
            ans+=freq[i]*pushes;
        }
        return ans;
    }
};