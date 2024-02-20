//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here
        
        ////SLIDING WINDOW PROTOCOL IN STRING
        
        //HERE WE WILL HAVE 2 POINTERS "FIRST" AND "SECOND"
        //SIMPLY WE WILL SLIDE A WINDOW HAVING IT'S LEFT BORDER AS "FIRST" POINTER AND IT,S RIGTH BORDER AS "SECOND" POINTER
        //WE WILL ADJUST ITS WIDTH ACCORDING TO SOME CONDITIONS .....IF ITS RIGHT BORDER ENCOUNTER ANY CHARACTER WHICH IS NOT PRESENT IN THE WINDOW before i.e a uniques character THEN WE WILL DECREMENT THE "DIFF" VARIABLLE AND MOVE SECOND POINTER FURTHUR
        //WHEN WE WILL HAVE ALL UNIQUE CHARACTERS PRESENT IN THE MAIN STRING I.E WHEN "DIFF" VARIABLE BECOMES 0 THEN WE WILL KNOW THAT OUR CURRENT WINDOW HAS ALL UNIQUE CHARACTERS AND STORE THE LENGTH OF CURRENT WINDOW IN SMALLEST VARIABLE BY COMAPARING IT WITH SMALLEST VARIABLE ITSELF TO FIND MINIMUM OF BOTH OF THEM(AS HERE SMALLEST LENGTH IS ASKED) THEN GREEDILY WE WILL TRY TO MAKE THE WIDTH OF WINDOW SHORT BY MOVING "FIRST" POINTER FURTHUR
        //IN THE HOPE THAT WE WILL GET A SUBSTRING OF SHORTER LENGTH THAN CURRENT ONE WHICH WILL STILL HAVE ALL UNIQUE ELEMENT
        //WHILE MOVING FIRST POINTER WHEN WE WILL KNOW THAT THE CHARACTER WE ARE REMOVING FROM WINDOW BY  INCREMENTING FIRST
        //IS NOT MORE PRESENT IN THE WINDOW OR HAVE FURTHUR NO OCCURANCE IN OUR WINDOW NOW ( IT CAN BE FOUND BY CHECKING WHEATHER THE CURRENT CHARACTER POINTED BY FIRST POINTER HAS ONLY 1 OCCURANCE )(IT CAN BE CHECKED FROM MAP) , THEN WE WILL REMOVE THAT AND INCREMENT DIFF AS BY REMOVING THAT WE LOST A UNIQUE CHARACTER
        //AND NOW WE WILL GREEDILY TRY FIND THAT UNIQUE CHARACTER BY MOVING SECOND POINTER FURTHUR
        
        //SO HERE STEPS ARE
        //first we will try to find out the no of unique characters present in our  input string
        //for example first exaample have 3 unique characters that are A,B and C
        //why these unique characters are required?????
        
        //because question has asked that we have to return the length of the smallest distinct window which must containg all these unique charcters atleast once
        
        // THEN WE WIILL PLACE FIRST AND SECOND POINTER AT 0TH INDEX
        // THERE WILL BE TWO CONDITION ONE IS WHEN "DIFF" VARIABLE IS GREATER THAN 0 I.E OUR CURRENT WINDOW DOESNOT CONTAIN ALL UNIQUE CHARACETR
        // AT THIS CONDDITION WE WILL MOVE SECOND POINTER TO FIND THAT UNIQUE ELEMENT
        // IF WE WILL FIND THE UNIQUE CHARACTER OR THE CHARACTER WHICH DO NOT HAVE OCCURANCE IN THE WINDOW THEN WE WILL INCREMENT THAT'S OCCURANCE IN MAP AND DECREMENT "DIFF" BY 1
        // ANOTHER WILL BE THE CONDITION WHEN "DIFF" VARIABLE WILL BE 0 I.E WE HAVE ALL UNIQUE CHARACTER IN OUR CURRENT  WINDOW , THEN WE WILL FIRST STORE ITS LENGTH BY COMPARING LENGHT WITH THE "SMALLEST" VARIABLE AND MOVE FIRST POINTER GREEDILY TO FIND MORE SHORTER DISTINCT WINDOW
        // IF WE WILL BE REMOVING A CHARCTER THAT HAS MORE THAN 1 OCCURANCE IN WINDOW THEN WE WILL REMOVE THAT AND DECREMENT THAT'S OCCURANCE IN MAP
        // AND IF WE WILL BE REMOVING A CHARACTER THAT HAS ONLY 1 OCCURANCE THAT MEANS AFTER REMOVING THAT OUR WINDOW WILL LOOSE A UNIQUE CHACATER
        // THEN WE WILL STILL REMOVE THAT IN THE HOPE THAT WE MIGHT GET MORE SHORTER LENGTH THAN CURRENT ONE
        
        // WE WILL DO IT UNTILL SECOND PONTER CROSSES THE LENGTH OF STRING
        
        //WHERE WILL WE STORE THE  LENGTH?????
        //WILL EXPLAIN THIS IN CODE
        
        //finding the unique character
        vector<int> map(256,0);
        for(char ch:str){
            map[ch]=1;
        }
        int diff=0;//diff pointer
        //counting diff
        for(int i=0;i<256;i++){
            if(map[i]==1){
                diff++;
            }
        }
        
        //now we have our diff value 
        //again we will be neeeding  a vector tto keep track of occurance of charaacters
        //instrd of ceating another vector we will reinitialise that vector with 0 by using "assign()" STL function
        //this functions  assigns a certain value to  all the indexes of a already initialised vector
        //syntax:-  vector_name.assign(vector_name.size(),value to be assigned);
        
        map.assign(map.size(),0);//assigning 0 to every index of the map
        
        //declaring first and second pointer
        int first=0,second=0;
        int smallest=str.size();//it will store the smallest length of smallest distinct window and initialy it is size of the string as that is the maximum possible answer
        
        while(second<str.size()){
            //in sliding window pronblems two conditions arise
            //one condition will move the second pointer or right border of the window ....here (diff>0)
            //while another charater will move the first pinter i.e left border of the winddow....here (diff==0)
            if(diff>0 && second<str.size()){
                if(map[str[second]]==0){
                    diff--;
                }
                map[str[second]]++;//increment the occurance as now it is occurined once
                second++;
            }
             
             
            while(diff==0){//why we used loop here ?????
                 //do dry run for first example you will clearly understand
                 //because in a situation where second index is present at last inndex of string and there "diff" value get to 0
                 //with it second pointer get increment and go outside the string and if we donot use loop here then the control will comppletely go outside of the whole loop
                 //if it happens we will not get chance to store the length of the currnt window also we will no able to check for more shorter length by moving first pointer
                 //hence we used loop here because to handle that situation (as in first example) and we can store the length of current window and also check for more shorter window by moving first pointer
                
                smallest=min(smallest,(second-first));//this is very very immportant
                //before moving first pointer the window we got now without moving  the first pointer also contain all the unique characters
                //so we have to compare that and store that
                //basically whenever value of diff becomes 0 we will store the length of current window
                //then only we start moving first pointer in search of more shorter substring
                
                if(map[str[first]] != 1){//if the character pointed by first ponter or the charactrer we want to remove now is not the last character of it,s own type then this will mean that 
                //even after removing it we will have that window which will still contain all unique character
                //for example in aabc , a,b and c are unique chacaret and if first is pointing a and second is pointing to c the aabc is our current window
                //here a has occurance of 2
                //if we want to remove a then even after removing it we will have abc which consists all the charcter in it so we will store its length as this can be a possible answer
                //so we will remove that and store the new length of current window in smallest variable 
                
                map[str[first]]--;
                first++;
                smallest=min(smallest,(second-first));///this is very very immportant
                //why we are doing (second-first) insted of second-first+1 ??????
                //because notice clearly that in the if block whatever be the value of 'diff' always second gets updated to next index
                //let at a point diff value becomes 0 then also second pointer will move to the next index of current window
                //so here the actual length of the window will be from first position to second-1 position 
                //so lenght will be:-  (second-1)-first+1 = second -first..........................................
                    
                }
                else{
                    map[str[first]]--;
                    first++;
                    diff++;//as by removing this current character we lost a unique character from our window so we will increment diff
                    //now as diff will be greater than 0 so again second pointer will move further to find the lost unique character and will include it in window
                    //this will continue untill second pointer crosses the range
                }
                    
                
            }
        }
        
        return smallest;
        
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends
