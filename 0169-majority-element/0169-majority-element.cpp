class Solution {
public:
    int majorityElement(vector<int>& nums) {

        //storing size of the vector
        int n=nums.size();

        //MOST IMPORTANT STEP
        //SORTING THE ARRAY
        sort(nums.begin(),nums.end());
        // BUT WHY WE NEED TO SORT??????????????????????????
        // BECAUSE SORTING WILL BRING ALL THE REPEATED ELEMENTS NEAR TO EACH OTHER WHICH WILL HELP US TO COUNT THEIR FREQUENCY IN ARRAY AT ONCE
        // FOR EXAMPLE ARRAY GIVEN IS:-{5,5,6,7,6,6,7,7,2,3,2,2,2,3,3,3} FOR THIS COUNTING FREQUENCY OF ANY NUMBER BECOMES VERY HARD FOR US BU IF WE SORT THIS:---
        // IT WILL BE:- {2,2,2,2,3,3,3,3,5,5,6,6,6,7,7,7}

        //IN THIS SORTED ARRAY IF WE WANT TO COUNT OCCURANCE OF ANY NUMBER AT ONCE WE COULD DO THAT
        //IF I WANT TO COUNT THE FREQUENCY OF 2 THEN I CAN COUNT THAT AT ONCE WHICH WILL BE 4 AND ALSO I CAN COMAPRE IT  WITH n/2 JUST AFTER COUNTING WHICH WILL HELP US TO FIND THE PERTICULAR MAJORITY ELEMENT

        // WE ARE TRYING TO CALCULATE THE FREQUENCY OF ANY ELEMENT AT ONCE BECAUSE IF WE DO THIS THEN WE COULD COMPARE THAT FREQUENCY OF THAT ELEMENT
        // WITH n/2 AND IF FREQUENCY BECOMES GREATER THAN n/2 THEN THAT WILL ELEMENT WILL BE THE MAJORITY ELEMENT HENCE WE WILL RETURN THAT ELEMENT


        //pointer that will traverse through the array to comapre "currentnum" variable
        //will know about "current" variable further
        int i=0;

        //loop
        while(i<n){
            int currentnum=nums[i];//this variable will store a number pointed by i and we will use this to count the frequency or repeatency of that number
            // untill the number pointed by i will be equal to currentnum we will increse count and i
            //when the number pointed by i will be different from currentnum then we will update currentnum with the number currently pointed by i

            int count=0;//for each different currentnum count will start from 0 
            while(i<n && nums[i]==currentnum){  //VERY VERY IMPORTANT EDGE CASE
            //IF I DO NOT INCLUDE (I<N) CONDITION THEN INSIDE LOOP ITSELF I CAN GO OUTSIDE THE RANGE OF NUM WHICH WILL THROUGH A ERROR AS THERE WE WOULD BE ACCESING INDEX WHICH IS NOT PRESENT
            //also i have to write it before (nums[i]==currentnum) this condition.......WHY?????????????
            //BECAUSE IMAGINE THAT THE I CROSSED THE INDEX RANGE AND THE IF WE PUT (nums[i]==currentnum) THIS AS FIRST CONDITION THE WE WILL BEE TRYING TO ACCES THE INDEX THAT DOESN'T EXIST
            count++;
            i++;
            }

            //for a certain number (which is stored in currentnum) once we calculated its frequency we will check that with this value of frequency or repeatency wheather the num is majjority element or not
            if(count>n/2){
                return currentnum;//as the frequency we are comapring with n/2 is the frequenct of number stored in "currentnum"
            }
        }
        return 0;//we have to this as we have to return somethig in all paths
    }
};