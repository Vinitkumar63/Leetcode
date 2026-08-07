class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int left_max=0;
        int right_max=0;
        int water=0;
        while(left<right){
            // check for left side first
            if(height[left]<= height[right]){
                if(height[left]>left_max)
               left_max= height[left];
                else
                water+=left_max-height[left];
                left++;
            }else{
                if(height[right]>right_max)
               right_max= height[right];
                else
                water+=right_max-height[right];
                right--;
            }
        }
        return water;
    }
};