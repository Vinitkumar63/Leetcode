class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();

        int i=0,j=0;
        int prev=0,curr=0;

        for(int k=0;k<=(m+n)/2;k++){
                prev=curr;

                if(i<m && (j>=n|| nums1[i]<=nums2[j])){
                    curr=nums1[i];
                    i++;
                }else{
                    curr=nums2[j];
                    j++;
                }
        }
        if((m+n)%2==1){
            return curr;
        }
        return (prev+double(curr))/2.0;
    }
};