class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
        [](vector<int>& a , vector<int>& b){
            return a[1]<b[1];
        });
        int count=0;
        int end_val=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end_val){
                count++;
            }
            else{
                end_val=intervals[i][1];
            }
        }
        return count;
    }
};