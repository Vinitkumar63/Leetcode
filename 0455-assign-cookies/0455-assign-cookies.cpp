class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end()); // they are child
        sort(s.begin(),s.end()); // they are cokkie

        int i=0 ,j=0,count=0;

        // i is child and j is cokiee
        while(i<g.size()&& j<s.size()){
            if(s[j]>=g[i]){
                i++;
                j++;
                count++;
            }else{
                j++;
            }
        }
        return count;
    }
};