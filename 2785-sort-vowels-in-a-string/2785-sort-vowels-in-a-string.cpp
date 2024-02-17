class Solution {
public:
    
    //function for checking wheather a characcter is vowel or  not
    //it returns true if ch is uppercase or lowercase vowel
    //here without writing the if condition i have written the condition in return statement itself
    //so here return condition acts as if condition if the condition in bracket satisfies then it returns true else false as its return type is bool

    bool isVowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
    }

    string sortVowels(string s) {
        //creating 2 vector for mapping or holding count of uppercase and  lowercase vowels
        vector<int>uppercase(26,0);
        vector<int>lowercase(26,0);
        //pos will  give the inndex where a character will be mapped
        int pos;

        for(char ch:s){//traversing each element of input string
        //if character in string is vowel and uppercase
        //then we will store count or frequency of that characcter in corresponding index of uppercase vector
            if(isVowel(ch)&&isupper(ch)){
            //    pos=ch-'A'; //finding corresponding index of ch
            //    uppercase[pos]++;

               //OR
               uppercase[ch-'A']++;
            }

                //if character in string is vowel and lowercase
        //then we will store count or frequency of that characcter in corresponding index of lowercase vector
            else if(isVowel(ch)&&islower(ch)){
                // pos=ch-'a';  //finding corresponding index of ch
                // lowercase[pos]++;

                //OR
                lowercase[ch-'a']++;
            }
        }

        //creating a string ans which wii store the vowels present in the input string in sorted manner
        //from this ans string we will put characters to string s
        string ans;

        //puting all uppercase vowel in ans string first
        for(int i=0;i<26;i++){
            //retrieving character from index
                char ch=i+'A';
            while(uppercase[i]>0){
                ans.push_back(ch);
                uppercase[i]--;
            }
        }

         //puting all lowercase vowel in ans string then
        for(int i=0;i<26;i++){
             //retriving character from index
                char ch=i+'a';
            while(lowercase[i]>0){
                ans.push_back(ch);
                lowercase[i]--;
            }
        }

        //now our ans string contains all the vowel present in string s in ascending order
        //so we have to just traverse the string s and put characters from ans string to vowel positions of string s
        //we will let consonants remain in their place
        //only replace  vowels of the string s with our alredy sorted vowels from ans string

        //this index variable will help us in traversing ans string
        int index=0;
        for(int i=0;i<s.length();i++){//this loop will traverse s string
            if(isVowel(s[i])){
              s[i]=ans[index];
              index++;
            }
        }
        //returning string in which consonants are in thee same place as input but vowels are sorted
        return s;
    }
};