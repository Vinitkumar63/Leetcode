class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return true;
            }
            //remove duplicies
            if(nums[low]==nums[mid]&& nums[mid]==nums[high]){
                low++;
                high--;
            }
            //now sorted left side we get
            else if(nums[low]<=nums[mid]){
                if(target>=nums[low]&& target<nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            // now right hand side we get
            else{
                if(target>nums[mid]&& target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return false;

    }
};