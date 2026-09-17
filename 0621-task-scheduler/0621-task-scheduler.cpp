class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        for(char ch : tasks) {
            freq[ch - 'A']++;
        }

        priority_queue<int> pq;

        for(int f : freq) {
            if(f > 0) {
                pq.push(f);
            }
        }

        int time = 0;

        while(!pq.empty()) {

            int cycle = n + 1;
            vector<int> remaining;

            // One complete cycle
            while(!pq.empty() && cycle > 0) {

                int f = pq.top();
                pq.pop();

                f--;
                time++;
                cycle--;

                if(f > 0) {
                    remaining.push_back(f);
                }
            }

            // Put tasks back AFTER completing the cycle
            for(int f : remaining) {
                pq.push(f);
            }

            // Remaining positions are idle
            if(!pq.empty()) {
                time += cycle;
            }
        }

        return time;
    }
};