class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        // now create a map;
        map<int,int>freq;

        for(int card:hand){
            freq[card]++;
        }
        // now write freq until zero
        while(!freq.empty()){

            int start=freq.begin()->first;

            for(int i=0;i<groupSize;i++){
                int card= start+i;

                if(freq.find(card)==freq.end()){ // here freq.end() means the card not found
                    return false;
                }
                freq[card]--;
                // if card ki frequency is equal to zero so rwmove that 
                if(freq[card]==0){
                freq.erase(card);
            }
            
            }
        }
        return true;
    }
};