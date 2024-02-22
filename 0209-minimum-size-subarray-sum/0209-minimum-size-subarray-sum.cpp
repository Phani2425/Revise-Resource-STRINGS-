class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //finding size of the nums array
        int size=nums.size();
        //creating a minimum variable which will store the minimum length of that subarray
        //initialising it with size of nums as any subarray will have length less that this for sure so it willl be easy for us to commapre
        int minimum=size;
        int sum=0;//this will strore sum of our current window

        //declaring two pointers which will traverse through the array
        int i=0,j=0;

        int flag=0;//this is the variable which will say that wheather there is any subarray present which have the sum equal to target
        //we will check at last that if it has same value 0 then that will mean that there is no subaaray having sum equal to or greater that target

        while(j<size && i<=j){//why we used condition (i<=j)???????
            //because let we have target 7 , and also we have 7 as an element in the array...........
            //there while greedily shortening the width of window to find shortest subaarry we will find shortest subaary length as 1 where i==j and both will be pointing 7
            //then i will move further and cross j
            //so now our ans will be 1 as there cannot be any subaaary having size short than 1 so we donot have to check further so we will come out of the loop and return minimum
            //this will improve our time complexity a little bit
            sum+=nums[j];

            while(sum>=target && i<=j){//why we used condition (i<=j)???????
            //because let we have target 7 , and also we have 7 as an element in the array...........
            //there while greedily shortening the width of window to find shortest subaarry we will find shortest subaary length as 1 where i==j and both will be pointing 7
            //then i will move further and cross j
            //so now our ans will be 1 as there cannot be any subaaary having size short than 1 so we donot have to check further so we will come out of the loop and return minimum
            //this will improve our time complexity a little bit

            //do brain storming that why we used while here??????????????
            //because once we got a subaary having sum greater than or equals to the target then greedily we will try to make the window width small in the hope that
            //we will find a more shorter subarray having sum equals to or greater than target {question also given to find the minimum size subaary sum}
                flag=1;//we did this to say that there exist a subaary whose sum is either equal to greater than target
                minimum=min(minimum,(j-i+1));
                //greedily shorting the width of the current window or subaaary by moving i forward
                //while shorting we are excluding a number pointed by i
                //before we have added that num to sum while including it in window
                //so while excluding it  we will substract that vlue from sum
                sum-=nums[i];
                ///moving i forward
                i++;
            }
            j++;
        }
        if(flag){//if flag is 1 this means we have enetred the  loop atleast once i.e there exist a subaary whose sum is either equal to greater than target
            return minimum;
        }
        else {
            return 0;
        }
        
    }
};