class Solution {
public:
    bool checkValidString(string s) {
        int minopen=0;
        int maxopen=0;

        for(char ch:s){
            if(ch=='('){
                minopen++;
                maxopen++;
        }else if(ch==')'){
            minopen--;
            maxopen--;
        }
        else{
            minopen--;
            maxopen++;
        }
        if(maxopen<0){
            return false;
        }
        minopen=max(0,minopen); // as minopen cannot be less than zero
    }
    return minopen==0;
    }
};