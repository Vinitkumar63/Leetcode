class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            // it helps to check ki vo sliding window ma ha ya nahi
            if(!dq.empty()&& dq.front()<=i-k)
            dq.pop_front();

                // now smaller no. ko remove karaga
                while(!dq.empty()&& nums[dq.back()]<=nums[i])
                dq.pop_back();

                dq.push_back(i);

                // now window complete hona pa
                if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};