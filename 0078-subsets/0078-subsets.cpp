class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // this problem is also solved by recursion 
        //here we use bit manipulation
        int n=nums.size();
        vector<vector<int>>ans;
       for(int mask=0;mask<(1<<n);mask++){
        vector<int>subset;
        for(int j=0;j<n;j++){
            if(mask & (1<<j)){
                subset.push_back(nums[j]);
            }
        }
        ans.push_back(subset);
       }
       return ans;
    }
};