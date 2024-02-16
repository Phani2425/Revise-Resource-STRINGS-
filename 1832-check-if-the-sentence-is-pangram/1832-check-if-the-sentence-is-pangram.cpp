class Solution {
public:
    bool checkIfPangram(string sentence) {
        //creating mapping vector
        vector<int> map(26,0);//map of size 26 i.e 0 to 25 index and each index is initialised with 0
        //it is initialise with 0 to make it easy to find the missing lowercase character in sentence
        //as coresponding index of a character will be incremented to 1 when we will encounter that character
        //at last if we found any index with value 0 that will mean that coresponidg lower character of that index is missing in string
        for(char ch:sentence){
           map[ch-'a']=1;
        }
        for(int occurance:map){
            if(occurance==0){
                return false;
            }
        }
        return true;
        
    }
};