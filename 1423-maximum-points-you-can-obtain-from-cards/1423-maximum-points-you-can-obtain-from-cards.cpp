class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int left_sum=0;
        for(int i=0;i<k;i++){          // k tak hi move karaga ya
            left_sum+=cardPoints[i];
        }
        int ans=left_sum;
        int right_sum=0;
        for(int i=1;i<=k;i++){
            left_sum-=cardPoints[k-i];
            right_sum+=cardPoints[n-i];
            ans=max(ans,left_sum+right_sum);
        }
        return ans;


    }
};