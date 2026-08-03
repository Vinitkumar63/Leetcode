class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff= start^goal;
        int count=0;
        while(diff){
            diff=diff &(diff-1);
                count++;
            
        }
        return count;
    }
};