class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int fartest=0;
        int current_end=0;

        for(int i=0;i<nums.size()-1;i++){
            fartest=max(fartest,i+nums[i]);  // i+nums[i] is the final destination where we reach nums[i] is the jump how long we can take
            if(i==current_end){
                     jumps++;
                      current_end=fartest;
            }
           
        }
        return jumps;
    }
    
};