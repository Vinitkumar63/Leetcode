class Solution {
public:

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;
    unordered_map<string, int> dist;

    void dfs(string word, string beginWord, vector<string>& path) {

        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (auto p : parent[word]) {
            path.push_back(p);

            dfs(p, beginWord, path);

            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        dist[beginWord] = 0;

        while (!q.empty()) {

            string word = q.front();
            q.pop();

            int d = dist[word];

            for (int i = 0; i < word.size(); i++) {

                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    temp[i] = ch;

                    if (!st.count(temp))
                        continue;

                    // First time visiting this word
                    if (!dist.count(temp)) {

                        dist[temp] = d + 1;

                        parent[temp].push_back(word);

                        q.push(temp);
                    }

                    // Another shortest way to reach temp
                    else if (dist[temp] == d + 1) {

                        parent[temp].push_back(word);
                    }
                }
            }
        }

        if (!dist.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};