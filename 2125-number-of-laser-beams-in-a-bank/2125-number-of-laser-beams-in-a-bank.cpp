class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       //in first thought i thought to take to pointers prev and next where prev will point to the first string where device is present
       //and next will traverse thhrough the array and count devices in each string 
       //after counting we will multiply no of devices present in string pointed by prev and string pointed by next to  get the no  of laser beams between them
       //then wee will do prev=next i.e transfer prev to the position where currently next  is present
       //but we will do this when string pointed by next have some devices otherswise we will let prev remain same 
       //and  neext will again start traversing the array

       //it can happen but it will littlle complex
       //as we have to first run a loop to place prev in the position where in the array for the first time no of devices are greater than 0
       //i.e we have to place it in the first string where any ddevice is present
       //then also we have to run multiple loops and have to check multiple conditions to achive ans
       //you can try it once

       //now we will try the optimised approach similar to the previous method but only witth one pointer and much simpler than the previous one

       //so here we will take two variable that are "previous one count"(poc) and "current one count"(coc) 
       //and we will use a pointer named "i" which wii traverse through each string of the array

       int poc=0,coc=0;
       int totalbeams=0;//this will count total no of beams

       for(int i=0;i<bank.size();i++){
           //counting the no of 1's or no of devices  in current string or string present at "i" index
           for(char ch:bank[i]){
               if(ch=='1'){
                   coc++;
               }
           }

           totalbeams+=(poc*coc);
           if(coc>0){//if current string have some devices then allocate poc value to coc
           //if current string doesnot have any device do not update poc value 
           //as if poc would be apointer then it would be only pointing strings which have devices(discussed in starting)
           //similar concept eill be applid here
               poc=coc;
           }
           coc=0;//current one count set to 0 as we will be counting no of devices in next string or next i from coc= 0
       }

       return totalbeams;
        
    }
};