//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        //creating vecctor for mapping both uppercase and lowercase character
        vector<int> upper(26,0);
        vector<int> lower(26,0);
        
        for(char ch:str){
            //if character is uppercase then mapping will be done in upper vector
            if(isupper(ch)){
                upper[ch-'A']++;
            }
            //if character is lowercase then mapping will be done in lower vector
            else{
                lower[ch-'a']++;
            }
        }
        
        //creating strigs which will strore uppercase character in sorted order and another will store lowercase character in sorted order
        //using these at last we willl replace the character fromm input string and make them sorted 
        string sortedupper,sortedlower;
        
        //sorting only uppercaase character and putting them in sortedupper string
        for(int i=0;i<26;i++){
            char ch=i+'A';
            while(upper[i]>0){
                sortedupper.push_back(ch);
                upper[i]--;
            }
        }
        //sorting only lowercaase character and putting them in sortedlower string
        
         for(int i=0;i<26;i++){
            char ch=i+'a';
            while(lower[i]>0){
                sortedlower.push_back(ch);
                lower[i]--;
            }
        }
        
        int u=0,l=0;//u is the index of sorteduppercase and l is the index of sortedlowercase
        
        for(int i=0;i<n;i++){
            if(isupper(str[i])){
                str[i]=sortedupper[u];
                u++;
            }
            else{
                str[i]=sortedlower[l];
                l++;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends