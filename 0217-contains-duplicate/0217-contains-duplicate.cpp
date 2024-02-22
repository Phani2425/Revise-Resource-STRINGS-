class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //we can not use mapping of freequency of elements to solve this as int given array elemnt can vary from -10^9 to 10^9
        //so  for this large range we cannot create frequency table

        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]==nums[j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        //THIS WILL HAVE A TIME COMPLEXITY OF O(n^2) WHICH WILL CUSE TLE IN CASE OF LARGE INPUTS
        //SO WE WILL TRY TO OPTIMISE IT A LITTLE

        //.............................................2ND METHOD......................................
        
        //sorting the array for easy comparisions
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;

        //THIS APPROACH HAS A TIME COMPLEXITY OF  O(n*logn).........

        //THIS QUESTION CAN ALSO BE SOLVED USING SET MEETHOD, MAP ,HASHMAP ETC USING WHICH WE CAN OPTIMISE THE TIME COMPLEXITY FURTHER MORE
        //SO AFTER STUDYING THESE TOPICS TRY TO SOLVE IT IN THESE WAYS TOO
        
    }
};