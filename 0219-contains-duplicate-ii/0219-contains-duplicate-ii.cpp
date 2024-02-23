class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //indirectly it is trying to say that i and j are two such indexes where value at i==value at j and difference beetwween these two indexes will be less than or equal to k
        //this means i have to search for j within k distace from i

        //handling the case where value of k is 0 ; if k=0 then i-j=0 that mean i and j are pointing to same element but it is asking that i and must be distinct indices
        if(k==0){
            return false;
        }
        //finding size of nums
        int size=nums.size();
        for(int i=0;i<size;i++){
            for(int j=i+1;j<=i+k;j++){
                if(j<size && nums[i]==nums[j]){
                    return true;
                }
            }
        }
        return false;

    }
};