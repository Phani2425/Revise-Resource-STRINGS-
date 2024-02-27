class Solution {
public:

    //FUNCTION FOR FILLING LPS TABLE
    void fill_LPS(vector<int> &LPS,vector<int> &pattern){
        LPS[0]=0;
        int pref=0,suff=1;
        while(suff<pattern.size()){
            if(pattern[pref]==pattern[suff]){
                LPS[suff]=pref+1;
                pref++;
                suff++;
            }
            else{
                if(pref==0){
                    LPS[suff]=0;
                    suff++;
                }
                else{
                    pref=LPS[pref-1];
                }
            }
        }
    }

    int KMP_search(vector<int>&Relation_nums,vector<int> &pattern){
        //KMP ALGORITHM WILL WORK THE SAME WAY IN ARRAY AND STRING AS IN BOTH WE ACCESS ELEMENTS BY INDEX VALUES
        //for kmp search we have to build lps table for pattern first
        vector<int> LPS(pattern.size());
        fill_LPS(LPS,pattern);
        
        //NOW WE WE WILL SEARCH AND COUNT THE OCCURANCES OF PATTREN IN RELATIONSHIP ARRAY OF NUMS I.E:-"Relation_nums"
        int count=0;
        int first=0;//TRAVERSE THE Relation_nums
        int second=0;//TRAVERSE THE PATTERN

        while(first<Relation_nums.size()){//we will traverse till end of Relation_nums as we have to count the no of occurances of pattern
            if(Relation_nums[first]==pattern[second]){
                first++;
                second++;

                if(second==pattern.size()){//AS SECOND POINTER GOES OUT OF BOUND OF PATTERN HENCE THIS WILL MEAN THAT
                    count++;//WE GOT A OCCURANCE OF PATTERN IN THE Relation_nums

                    second=LPS[second-1];
                }
            }
            else{
                if(second==0){
                    first++;
                }
                else{
                    second=LPS[second-1];
                }
            }
        }
        //returning the no of timmes we got pattern in relation-ship array of nums
        return count;
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        //INTUTION:- WHENEVER THE QUESTION WILL ASK TO SERACH THE OCCURANCE A PATTERN IN A STRING OR IT ASKS TO RETURN THE NO OF OCCURANCES OF A PATTERN IN STRING
        //OR TO RETURN THE INDEXES WHERE PATTERN IS PRESENT IN THE STRING OR ANYTHING WHICH INCLUDES SEARCHING A SUBSTRING IN A STRING THERE 
        //THE MOST OPTIMISED WAY THAT CAN BE USED IS KMP ALGORITHM OF STRING MATCHING

        //IN THIS QUESTION ALSO IT HAS ASKED  TO RETURN the count of subarrays in nums that match the pattern
        //SO HERE WE WILL APPLY KMP ALGORITHM OF STRING MATCHING

        //BUT HOW ????? HERE PATTERN IS NOT DIRECTLY PRESENT IN THE NUMS............ 
        // SO HOW  CAN WE APPLY KMP ALGORITHM?????

        //THE QUESTION JUST SEEMS DIFFICULT BUT ACTUALY IT IS NOT IT IS VERY VERY SIMPLE IF WE CLOSELY NOTICE THE PATTERN NAD NUMS
        //EVEN I SOLVED IT WITHOUT ANY HELP// SO IT  IS THAT SIMPLE JUST THINK OUT OF THE  BOX

        //HERE UPON SEEING THE QUESTION I WAS THINKING THAT HOW CAN I FIND THE  SUBBARRAYS WHICH WILL MATCH THE PATTERN AS PATTERN IS NOT DIRECTLY PRESENT IN NUMS
        //THEN FOR SOME TIME I THOUGHT I WOULD SOLVE IT USING SLIDING WINDOW TECHNIQUE
        //BUT THEN SUDDENLY I REALISED THAT THE ELEMENTS OF PATTERN IS REPRESENTING THE RELATIONSHIP BETWEEN TWO CONSECUTIVE ELEMENTS OF NUMS
        
        //WHEN PATTERN HAVE 0 IN ITS KTH INDEX THAT WILL MEAN THAT IN THE SUBARRAY WHICH WILL MATCH WITH THE PATTERN THE K+1TH ELEMENT WILL BE EQUAL TO KTH ELEMENT
        //nums[i + k + 1] == nums[i + k] if pattern[k] == 0
        //WHEN PATTERN HAVE 1 IN ITS KTH INDEX THAT WILL MEAN THAT IN THE SUBARRAY WHICH WILL MATCH WITH THE PATTERN THE K+1TH ELEMENT WILL BE GREATER THAN KTH ELEMENT
        //nums[i + k + 1] > nums[i + k] if pattern[k] == 1.
        //WHEN PATTERN HAVE -1 IN ITS KTH INDEX THAT WILL MEAN THAT IN THE SUBARRAY WHICH WILL MATCH WITH THE PATTERN THE K+1TH ELEMENT WILL BE LESS THAN KTH ELEMENT
        // nums[i + k + 1] < nums[i + k] if pattern[k] == -1.

 //FOR EXAMPLE :-The pattern [1,1] indicates that we are looking for strictly increasing subarrays of size 3. In the array nums, the subarrays [1,2,3], [2,3,4], [3,4,5], and [4,5,6] match this pattern.
// Hence, there are 4 subarrays in nums that match the pattern.

// Input: nums = [1,4,4,1,3,5,5,3], pattern = [1,0,-1]
// Output: 2
// Explanation: Here, the pattern [1,0,-1] indicates that we are looking for a sequence where the first number is smaller than the second, the second is equal to the third, and the third is greater than the fourth. In the array nums, the subarrays [1,4,4,1], and [3,5,5,3] match this pattern.
// Hence, there are 2 subarrays in nums that match the pattern.

//SO MY WORK HERE IS TO JUST COUNT THE NO OF SUBARRAYS PRESEENT IN NUMS WHICH WILL HAVE SAME RELATIONS BETWEEN ITS ELEMENTS AS LIKE GIVEN IN PATTERN
//SO MAKING IT MORE SIMPLE I HAVE TO FIND THE SAME RELATIONS LIKE GIVEN IN PATTERN
//HOW CAN I DO THAT????

//INTUTION:-----IF I SIMPLY COULD REWRITE THE NUMS IN TERMS OF THE RELATIONSHIP BETWEEN ITS CONSECUTIVE ELEMENTS THEN I CAN DIRECTLY SEARCH FOR PATTERN IN THAT NEWLY BUILD RELATIONSHIP ARRAY
//FOR EXAMPLE THE RELATIONSHIP ARRAY FOR nums = [1,4,4,1,3,5,5,3] IS :-RELATION_NUMS=[1,0,-1,1,1,0,-1]
//HERE IN 'RELATION_NUMS' I HAVE JUST WROTE THE RELATIONSHIP BETWEEN CONSECUTIVE ELEMENTS OF NUMS AS PER THE GIVEN RULES:-
// nums[i + k + 1] > nums[i + k] if pattern[k] == 1.
// nums[i + k + 1] == nums[i + k] if pattern[k] == 0.
// nums[i + k + 1] < nums[i + k] if pattern[k] == -1.

//NOW IN THE RELATIONN SHIP ARRAY I CAN DIRECTLY FIND THE PATTERN AND COUNT THE NO OF TIMES IT IS OCCURING IN IT WHICH WIIL BE THE SAME VALUE AS the count of subarrays in nums that match the pattern.
//SO THAT VALUE WILL BE OUR ANSWER

//FOR BUILDING RELATIONSHIP ARRAY WE WILL USE A POINTER WHICH WILL TRVERSE THE NUMS ARRAY
vector<int>Relation_nums;
for(int i=1;i<nums.size();i++){
    if(nums[i]==nums[i-1]){
        Relation_nums.push_back(0);
    }
    else if(nums[i]>nums[i-1]){
        Relation_nums.push_back(1);
    }
    else{
        Relation_nums.push_back(-1);
    }
}

//NOW WE WILL SERACH PATTERN IN RELATIONSHIP ARRAY BY USING KMP ALGORITHM AND COUNT THE NO OF IT'S OCCURANCES
int count=KMP_search(Relation_nums,pattern);

return count;
 
    }
};