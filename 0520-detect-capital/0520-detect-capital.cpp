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

//this can also be done creating and using two function to which input word will be provided as parameter
//one function will check wheather all characters of the provided word is uppercase
//another will check wheather all character of the passed word is lowercase
//ok now we have checked first 2 conditions of question but what about the third condition
//can we handle that with these 2 creaated function?????
//OFCOURSE
//we know that if all characters of word except 1st character will be small then wheather the 1st character is 
//capital or not in both cases that will be correct use of capital
//so we will pass the substring of word starting from index 1(as we will check all character except 1st one i.e 0th inndex)
//if all these function call return 1 then we will return true

//if( allcapital(word) , allsmall(word) , allsmall(word.substr(1,word.length()-1))){
   // return true;
// }
// return false;
