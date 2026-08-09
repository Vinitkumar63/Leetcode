class Solution {
public:
long long summax(vector<int>&nums){
    int n=nums.size();
    vector<int>left(n),right(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        // this is for previous greater than
        while(!st.empty()&& nums[st.top()]<=nums[i]){
            st.pop();
        }
        if(st.empty())
        left[i]=i+1;
        else
        left[i]=i-st.top();

        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    // next greater than
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&& nums[st.top()]<nums[i]){
            st.pop();
        }
        if(st.empty())
        right[i]=n-i;
        else
        right[i]=st.top()-i;

        st.push(i);
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+= 1LL* nums[i]*left[i]*right[i];
    }
    return ans;

}
// now for minimum
long long summin(vector<int>&nums){
 int n=nums.size();
    vector<int>left(n),right(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        // this is for previous greater than
        while(!st.empty()&& nums[st.top()]>=nums[i]){
            st.pop();
        }
        if(st.empty())
        left[i]=i+1;
        else
        left[i]=i-st.top();

        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    // next greater than
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&& nums[st.top()]>nums[i]){
            st.pop();
        }
        if(st.empty())
        right[i]=n-i;
        else
        right[i]=st.top()-i;

        st.push(i);
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+= 1LL* nums[i]*left[i]*right[i];
    }
    return ans;

}


    long long subArrayRanges(vector<int>& nums) {
        return summax(nums)-summin(nums);
    }
};