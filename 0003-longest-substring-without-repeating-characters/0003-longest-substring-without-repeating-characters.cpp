class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //SLIDING WINDOW PROTOCOL IN STRING
        
        //HERE WE WILL HAVE 2 POINTERS "FIRST" AND "SECOND"
        //SIMPLY WE WILL SLIDE A WINDOW HAVING IT'S LEFT BORDER AS "FIRST" POINTER AND IT,S RIGTH BORDER AS "SECOND" POINTER
        //WE WILL ADJUST ITS WIDTH ACCORDING TO SOME CONDITIONS .....IF ITS RIGHT BORDER ENCOUNTER ANY CHARACTER WHICH IS NOT PRESENT IN THE WINDOW THEN ITS WIDTH WILL INCRESE  BY MOVING ITS RIGHT BORDER OR  "SECOND" POINTER
        //ELSE IF ITS RIGHT BORDER ENCOUNTER ANY CHARACTER WHICH IS ALREADY PRESENT IN THE WINDOW THEN ITS WIDTH WILL DECREASED BY REMOVING THAT PREVIOUSLY OCCURED CHARACTER FROM THE WINDOW BY USING ITS LEFT BORDER "FIRST" POINTER
        
        int longest=0;//this  variable will store the length of longest possible substring which wii not have any  repeatinng character
        int first=0,second=0;//two pointer where second pointer will check wheather any character has already occured before
        //betwwen current first and second pointer and according to this firrst pointeer will move to remove that already occured character from the current  substring

        vector<int> map(256,0);// 256 SIZE IS TAKEN TO MAP ALL POSSIBLE CHARACTERS AS IN QUES CONSTRAINT IS STRING CAN HAVE EVERY POSSIBLE CHARACETR AND WE HAVE TOTAL 256 CHARACTER
        //SO BY TAKING 256 SIZE WE COULD MAP EACH ONE IF THEY WILL BE PRESENT IN STRING
        //this is a vector  which will be used as map to keep track of  wheather any character has already occured between current first and second pointer
        //the character that already occured  will have 1 in the corresponding index off the map otherwise it will contain 0 in correspondingg index of character
        //when ever we will found any  unooccuered chaaracter in second pointer theen we will put 1 inn the corresponding index of that character
        //and when we will found any already occured characcter in second pointer then we will move first pointer and put 0 for all characters in their correspondding  index of map untill we reach that character
        //when first pointer will reach that character we will put 0 in the character's corresponding index of map and move first pointer to its next index
        //and we will do all these untill seconnd pointeer is less  than the size of string or until the second pointer crosses the last index of string s

        while(second<s.size()){
            if(map[s[second]]==0){//if character is unoccured
                map[s[second]]=1;
                longest=max(longest,(second-first+1));//maximum value between these two will be stored in longeest variable
                //it is liitle bit simillar to greedy approach
                //as we are storing ans and greedily trying to find more lengthy substring having no repeating character
                second++;
            }

            else{//if element pointed by secondd pointer has already occured ( in the substring betwwen current first and second pointer){IMP}
                while(s[first]!=s[second]){
                    map[s[first]]=0;//declare all character pointed by first unoccureed by puuting 0 in their corresponding index of map
                    first++;//move first
                }
                //now at this point  first would be pointing the charaacter we want to remove from our substring now
                //so lets reemove that by doing first++.....
                //but before that lets declare that unoccured as we are removing that from our current substring hence for our cuurent substring it is not occuered yet
                map[s[first]]=0;
                    first++;
            }
        }
        //now reeturn result
        return longest;
    }
};
