//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    
	    //..............................BRUTE FORCE APPROACH........................................
	    //in this we will comapre all possible prefixs with all possible suffixes of the string
	    //while comparing if any pair of prefix suffix becomes equal the we will store length of that
	    
	    //as the size of prefix and suffix can vary from 1 to size-1 of the size of the string
	    //for example a string of size 5 can have prefix and suffix size from 1 to 4 as whole string can not be prefix or suffix
	   // so we will create a  loop which will decide the size of the prefix and suffix and go from 1 to size -1
	   
	   //variable that will store the length of longest prefix suffix
	   
	   //     int longest=0;
	   
	   //we are starting it with 0 as this will help us in comparisions and also if any string does not have any prefix suffix  then this value will not change
	   ////and at last we will return longest which is 0
	   
	   ////strings that will store prefix and suffixes
	   
	   //   string prefix;
	   //   string suffix;
	   
	   // for(int i=1;i<s.size();i++){
	   //    prefix=s.substr(0,i);//prefix starts from 0 index
	   //    suffix=s.substr(s.size()-i, i);
	       
	   //    if(prefix==suffix){
	   //        int currentsize=prefix.length();//or suffix.length(); as both have same length due to i
	   //        longest=max(longest,currentsize);//comparing previous size with current size
	   //    }
	   //}
	   // return longest;
	   
	   //BUT THIS WILL TAKE O(N^2) TIME WHICH WILL CAUSE TIME LIMIT EXCCED AS QUESTION HAS GIVEN TO SOLVE IT WITH O(S) WHERE S IS THE SIZE OF THE STRING
	   
	   //SO ANOTHER APPROACH WE CAN USE IS THE BETTER APPROACH IN WHICH WE WILL BE USING TWO POINTERS TO SOLVE THIS
	   //THAT WILL ALSO TAKE O(N^2) TIME 
	   
	   //..................................BETTER APPROACH..........................................
	   
	   //   vector<int> possible;
	   
	   //  for(int i=1;i<s.size();i++){
	   //    if(s[i]==s[0]){
	   //        possible.push_back(i);
	   //    }
	   // }
	   
	   ////EDGE CASE
	   
	   // if(possible.size()==0){
	   //    return 0;
	   // }
	   
	   // int i=0;
	   // int index=0;//this will traverse over possible vector
	   // int j=possible[index];
	   
	   // while(j<s.size()){
	   //    if(s[i]==s[j]){
	   //        i++;j++;
	   //    }
	   //    else{
	   //        i=0;   ///starting i from 0 again
	   //        index++;
	   //        if(index<possible.size()){
	   //            j=possible[index];
	   //        }
	   //        else{
	   //            break;
	   //        }
	   //    }
	   //}
	   // return i;   //   very imporatant point //why we are returning i 
	   
	   
	   //..............................OPTIMISED APPROACH................................
	   
	   //LPS TABLE CONCEPT
	   
	   //creating lps table having same size as the string such that at last index of lps table we will have that value which will be the lenght of longest prefix suffix of the whole string
	   vector<int> LPS(s.length());
	   
	   LPS[0]=0;
	   
	   
	   //initialising the pointers
	   int pref=0,suff=1; ///we will use suffix pointer to put values in LPS table
	   
	   while(suff<s.length()){ //or while(suff<LPS.SIZE()){} whic means untill we go out of bound of string or untill we complete filling the LPS table
	   
	    if(s[pref]==s[suff])
	    {
	        LPS[suff]=pref+1;
	        pref++;
	        suff++;
	    }
	    
	    else
	    {
	        if(pref==0){
	            LPS[suff]=0;
	            suff++;
	        }
	        else{  //we will try to find a pattern which is present in prefix of string and before the character pointed by 'suff'
	            pref=LPS[pref-1];
	        }
	    }
	       
	   }
	   return LPS[LPS.size()-1];  //returning the last index of LPS
	   
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends