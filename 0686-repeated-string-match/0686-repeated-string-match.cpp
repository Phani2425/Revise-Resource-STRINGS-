class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        //SO HERE MY INTUTION IS TO REPEAT STRING A UNTIL IT REACHES THE SAME OR SLIGHTLY MORE SIZE THAN THE SIZE OF STRING B 
        //BECAUSE THIS THE FORMOST AND MOST BASIC CONDITION THAT A SUBSTRING ALWAYS HAVE EITHER SAME OR LESS SIZE AS COMPARED TO THE STRING
        
        //AS OUR WORK IS TO RETURN THE MINIMUM REPEATATION QUANTITY HENCE
        //SO AFTER REPEATING UNTILL IT HAVE SIZE EQUAL TO OR GREATER THAN THE SIZE OF STRING B WE WILL CHECK WHEATHER STRING B CAN BE A SUBSTRING OF STRING A NOW
        //IF YES THEN WE WILL RETURN THAT REPEATATION NUMBER ELSE WE WILL REPEAT STRING B FOR A EXTRA ONE TIME
        //THEN AGAIN WE WILL CHECK WHEATHER B IS SUBSTRING OF A 
        //IF STILL B IS NOT A SUBSTRING  THEN IT CAN NEVER BE SUBSTRING OF A AND WE WILL RETURN -1....
        //FOR EXAMPLE:- A = ABC  ,B=ABCD 
        //HERE WHATEVER TIMES I REPEAT A ,,, B CAN NEVER BE A SUBSTRING OF A AS THE CHARACTER D CAN NEVER APPEAR IN A EVEN AFTER COUNTLESS REPEATATION
        
        //LETS FIND THE SIZE OF EACH STRING
        int Asize=a.length();
        int Bsize=b.length();

        if(a==b){
            return 1;
        }

        int repeat=1;

         string str=a;

         while(str.size()<b.size()){
             str+=a;
             repeat++;
         }

        //NOW WE WILL CHECK WHEATHER B IS SUBSTRING OF A OR NOT BASICALLY WE WILL DO STRING MATCHING
        //FOR THAT WE CAN USE KMP ALGORITHM OF STRING MATCHING
        //ASLO WE CAN USE FIND FUNCTION OF STL
         
        int flag=0;
        while(1){
            if(str.find(b) == string:: npos){
                if(flag==1){//IF EVEN AFTER REPEATING THE STRING FOR A EXTRA TIME STILL B IS  NOT A SUBSTRING A THE IT CAN NEVER BE SO RETURN -1
                    return -1;
                }
                str=str+a;//REPEATING STRING A FOR A EXTRA TIME
                repeat++;
                flag=1;//THIS MEANS WE HAVE REPEATDED THE STRING A FOR A EXTRA TIME
            }
            else{
                return repeat;
            }
        }

    }
};