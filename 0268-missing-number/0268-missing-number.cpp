class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int sum=0;
        // int sum2=0;
        // for (int i=0;i<=nums.size();i++){
        //     sum=sum+i;
        // }
        // for(int i=0;i<nums.size();i++){
        //     sum2=sum2+nums[i];
        // }

        // return sum-sum2;

        //......................................USING XOR.............................................

        int result=0;
        for(int i=0;i<=nums.size();i++){
          result=result^i;
        }

        for(int i=0;i<nums.size();i++){
            result=result^nums[i];
        }

        return result;

        //....................................USING BINARY SEARCH OR DIVIDE AND CONQUER CONCEPPT..............................
        
        // sort(nums.begin(),nums.end());//  sorting the array to apply binary search
        // if(nums[0]==1){
        //     return 0;//if 0 is the missing element then directly return 0 as our program cannot handle that case
        //     //why it cant handle the case when 0 is missing elemennt ????? Dry run that case with program to know abouuut it
        // }
        // int start=0,end=nums.size()-1;
        // int ansindex;

        // while(start<=end){
        //     int mid=start+(end-start)/2;

        //     if(mid==nums[mid]){//after sorting if the value stored in  a index is same as that index that will mean that untill that element no element is missing and the missing element may lie in right side of that index
        //     //also we know that if the value stored in  a index is same as that index then that value could be the previous value of missing element
        //     //hence we will store that and then move  to right by doing start=mid+1 

        //         ansindex=mid;
        //         start=mid+1;
        //     }
        //     else if(mid<nums[mid]){
        //         end=mid-1;
        //     }

        // }
        // return ansindex+1;
    }
};