class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);

        for(char ch:tasks){
            freq[ch-'A']++;
        }
        int max_freq=0;
        for(int f:freq){
            max_freq=max(max_freq,f);
        }
        int count=0;
        for(int f:freq){
            if(f==max_freq){
                count++;
            }
        }
        int time=(max_freq-1)*(n+1)+count;

        return max( (int)tasks.size(),time);
    }
};