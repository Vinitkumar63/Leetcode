class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>st(wordList.begin(), wordList.end());

        if(st.find(endWord)==st.end()){
            return 0;
            }

            queue<string>q;

            q.push(beginWord);
            int steps=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string word= q.front();
                q.pop();

                for(int j=0;j<word.size();j++){

                    char original=word[j];

                    for(char ch='a';ch<='z';ch++){
                        word[j]=ch;

                        if(word==endWord){
                            return steps+1;
                        }

                        if(st.find(word)!=st.end()){
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[j]=original;
                }
            }
            steps++;
        }
        return 0;
    }
};