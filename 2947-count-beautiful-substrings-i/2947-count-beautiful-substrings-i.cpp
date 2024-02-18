class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        //here we will be creatinng a loop which is generaly used to get substrings from a string
        //we can do it by finding all possible substrings of the string then for each substring we will check 
        //wheather that substrring is beautiful or not by checking given conditionds in the question
        //if we will get a string that is beautiful then we will increase the count by 1 
        //count variable will count the total no of beautiful substrings
        int count=0;
        //but it wwill be highly complex as every time we have to extract a substring then we have to count the no of 
        //vowels and consonants in that substring then we have to check conditions for that
        //if the length of string will be more then we have count for vowels and consonants may time as that will have a lot of substring

        //so if we could count vowels and consonants of substring at once while finding substrings using loop then it will be very simmple

        for(int i=0;i<s.length();i++){
        int vowelcount=0;
        int conscount=0;
           
             for(int j=i;j<s.length();j++){
                 //checking wheather the character pointed by j is vowel or consonant 
                 //basicaly we are calculating the no of vowels and consonants present in current substring i.e between i and j pointer
                 //the characters over which we are moving j pointer we are checking wheather it is vowel or not and incrementing corresponding variable
                 //for a substring after calculating them we will check if the count of vowel and consonant of a substring satisfy the condition of beautiful string 
                //if it satisfies then we will increment count by 1

                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                    vowelcount++;
                }
                else{
                    conscount++;
                }

                //checking if this substring betwwen i and j satisfies condition of beautiful string
                if(vowelcount == conscount && (vowelcount*conscount)% k == 0){
                     count++;
                }

             }

        }
        return count;
    }
};