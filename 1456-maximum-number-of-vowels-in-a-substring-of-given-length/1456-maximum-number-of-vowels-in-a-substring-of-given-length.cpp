class Solution {
public:
     
    //writing a function that will check wheather a character is vowel or not
    bool isvowel(char & ch){
        if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o' || ch=='u'){//only included the smallcase letters as question is given in constarint that the string will have only small case characteers
             return true;
        }
        return false;
    } 

    int maxVowels(string s, int k) {
        //lets develop inntution in this question first

        //it is basically asking to return the higheest no of vowel that is present in any substring having length k in the given string
        //so beefore moving anywhere we are clear that we have count the no of vowels in a substring so for that lets create a variable
        int vowelcount=0;//this variable will count the no of vowels in a substring
        int maxvowel=0;//this will be comapred while finding the maximum no of vowel in a substring

        //<<<<<<<<<<<<<< BRUTE FORCE APPROACH >>>>>>>>>>>>>>>>>>>

        // we will find all posible substring having length k in the given string
        //and count the no of vowels they have in them
        //and return the maximmum count value
        //this approach will have a time complexity of:- O(N*K) 
        //AS WE ARE TRAVERSING THROUGH EACH ELEMENT OF THE STRING AND FOR EACH ELEMENT WE ARE FINDING K LENGTH SUBSTRING
        //SUBSTR() FUNNCTION TAKES TIME SAME AS THE LENGTH OF THE SUBSTRING WE ARE EXTRACTING

        //<<<<<<<<<<<<<<<<<<<<<<<<<<<< OPTIMAL APPROACH >>>>>>>>>>>>>>>>>>>>>>>>>

        //AS IT IS ASKING TO CHECK FOR THE SUBSTRINGS IN A STRING SO ACCORDING TO  PATTERNS OF SLIDING WINDOW TECHNIQE THIS IS THE PERFECCT CANDIDATE TO BE SOLVED USING SLIDING WINDOW
        //AS ALSO WE HAVE O(N*K) TIME COMPLEXITY IN BRTTUE FORCE APPROACH SO TO DECREASE IT MORE  TO O(N) WE HAVE TO USE SILDIGN WINDOW WHICH WILL SOLVE IT MORE OPTIMALY

        //declaring pointers
        int i=0,j=0;
        //finding size of the  string
        int size=s.length();
       
        while(j<size){

            if(isvowel(s[j])){
                vowelcount++;
            }

            if(j-i+1==k){
                maxvowel=max(maxvowel,vowelcount);
              if(isvowel(s[i])){
                  vowelcount--;
              }
              i++;
            }
            
                j++;
            
        }

        return maxvowel; 
    }
};