//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        //factorial of a number N can be found by:- N*N-1*N-2*N-3*N-4* ...........3*2*1
        //it can be also written as 1*2*3*4*5*6...........*N-1*N
        //here also we will do the same
        //we will start from 1 and multiply all numbers till N with it
        
        //but the problem is here N can be large and while multiplication the result of multiplication can also 
        //exceed range of integer and even long long
        //that is why we cann,t store their multiplication values in any of the variable
        
        //here 2 optiions remain that is string.
        //as we know when ever we need to store very large number we use string
        // but the problem using string is each time we want to multiply a number with any digit from the string we have to
        // convert that string element to integer then we can multiply and again we have to convert that result to character for storing it in string
        
        // this process will be very complex
        // also this function is asking a vector in return hence we have to again copy all character from final string to a vector to return
        
        // we previously know that string behaves like an array and here also if we use string we would be accesing string elements using index values
        //then why should not we use vector in which in each index we will store a single digit  this will solve all the problems
        //we were facing in string and also we will avoid "integer overflow  error" as array can of any size
        
        //so we will create a vector and initialize it with 1. then we will run a loop from 2 to N and multiply each one with the value stored in vector
        //while multiplying we will store the multiplication result from left to right of vector but in reverse order to allow the number to grow further
        //what does this meean?????
        //means if we have 12 in vector it will be stored like :- 2 1 ... why we are doing like this????
        //because let when we will multiply 10 with the number stored in vector then it will first get multipliedd with 2:= 10*2 = 20 ,
        //where 0 will be stored in the place of 2 i.e at 0th index and 2 will be stored in "carry" and will be carried to next index
        //then 10 will be multiplied with 1 which will form:- 10*1+carry=10+2=12......where 2 will be stored at position of 1 i.e at index:- 1
        //and 1 will be carried which will then pushed back to vector converting the vector from:- 2 1 to:- 0 2 1  .....
        //here 12 growed to 120
        //this implies by storing them in reverse order heelps them to grow further towards  right side and if we store it
        // like 12 then where could it grow?????????????
        
        vector<int> ans(1,1);//vector having size 1 and at 0th index it has value 1
        
        //creating loop from 2 to N
        for(int i=2;i<=N;i++){
            int carry=0;
            int index=0;//index will traverse through current vector indexes or digits to multiply them with i
            
            //loop for traversing vector or digits to multiply them with i
            while(index<ans.size()){
                int result= i * ans[index] + carry;
                ans[index]=result%10;
                carry=result/10;
                index++;
            }
            
            while(carry>0){
                ans.push_back(carry%10);
                carry/=10;
                index++;
            }
        }
        
        reverse(ans.begin(),ans.end());//reversing the ans to get actual answer as in this programm wee were storing the answer  in reverse order to let it grow
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends