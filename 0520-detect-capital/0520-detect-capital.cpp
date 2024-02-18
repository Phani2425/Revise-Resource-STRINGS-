class Solution {
public:
    bool detectCapitalUse(string word) {
        //variable that will count no of capital letters
        int capcount=0;
        for(char ch:word){
            if(ch>='A' && ch<='Z'){ //here we also can use predefined stl function :- isupper() 
                capcount++;
            }
        }
         //checking condition to detect correct usage of capital
            if(capcount==word.length() || capcount==0 || capcount==1 && isupper(word[0])){
                return true;
            }
            return false;
    }
};