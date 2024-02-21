//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        
        //so the question is asking for finding repeating and missing element in a array
        //we can do that by mapping the occurances of the element in a array
        //if the element has 0 occurance then that will mean that element is the missing  element
        //and if  that elelment have occurance of 2 then that will mean the element is thhe repeated element
        
        //we can do this mapping by creating a new array having n size i.e if n is 7 then the original array will have size of 7 (0 to 6 index)
        //but in the new array we can make its size 8 (index 0 to 7) so that it will be easy to map elements from 1 to 7
        //occurance of 1 will be stored at 1st index of our array,occ of 2 will be stored in 2nd index similarly occurance of 7 will be stored in index 7 of the array
        
        //but can wwe optimise it a little???
        //sure...........we can store occurance of a element in (element-1)th index
        //occ of 1 will be stored in 0th index,occ of 2 will be stored at 1st index..........occ of 7 will be stored at 6th index
        //so that we have to only create array of size same as original array
        
        // can we do it without using any extra space???????
        //yes we can do it......................
        //we will use "storage of 2 number in one place" concept
        //int this concept  we were storing 2 numbers in one variable from which we can retrive one number by division and another one by modulos operater
        //here we will do the same
        //but here we have to map elements from 1 to n in index of 1 to n-1(original array) hence we have to store occurance of a element in (element-1)th index
        //so that occurance of n can be stored in n-1th index
        //so to do this easyly and complexities we will update all elememnts of the array by element-1 .......
        //for example 6 will be updated by 6-1=5 ,7 will be updated by 7-1=6..........n will be updated with n-1  so when ever
        //we will encounter with 0(1 became 0 after updation) will store occurance of that in 0th index
        //while returning we will return index+1
        //index = element-1     ........>>>>  element = index+1    ....................
        
        //also how to store both element and occurance at same place
        //so in this array occurance can never be more than 2 ....it will vary  within 0 to 2
        //we know that 2 number can be stored in one place by:- number3=number1*x +number2
        // where:- number1=number3/X
        // number2=number3%X
        
        //so if we will take x as 3 (x can be anything greater than 2) (as range of occurance is from 0 to 2) and element as number1 and no of occurances as number2 which will be always less that X
        //then we can store them both in one place
        
        //so after making element-1 we will multiply 3 with each element such that we can retrive them by dividing 3 with them
        
        ///creating ans vector
        vector<int> ans;
        
        //updating  the elements of array by elemnt-1 and then we will multiply 3 or any otherr number with them
        for(int i=0;i<arr.size();i++){
            //element -1
            arr[i]--;
            //multiplying with 3
            arr[i]=arr[i]*3;
            
        }
        
        //traversing the array again to count frequencies of element and then storing tthose frequencies in corresponding index of same array
        for(int i=0;i<arr.size();i++){
            // element can be found by doing arr[i]/3 as previously we have multiplieed elements with 3
            arr[arr[i]/3]++;
        }
        
        //traversing the array again to find indexes which stores 2 or 0 occuracne
        int repeat;
        int missing;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%3==2){//repeating element hence occurance 2
                 repeat=i+1;//doing i+1 to get actual element value as occurance of element was stored in element -1
            }
            if(arr[i]%3==0){//missing element hence occurance 0
                 missing=i+1;//doing i+1 to get actual element value as occurance of element was stored in element -1
            }
        }
        
        ans.push_back(repeat);
        ans.push_back(missing);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends