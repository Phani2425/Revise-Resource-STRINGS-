//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string sort(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << sort(s) << endl;
    }
return 0;
}




// } Driver Code Ends


string sort(string s){
    //complete the function here
    
    //creating a vector for mapping
    vector <int> map(26,0);//we initialised it with 0 because it helps us to differeentiate between elemeents which are
                           //present in the string and which are absent in the string
    
    //maping the frequencies of character
    for(char ch:s){
        map[ch -'a']++;
    }
    
    //traversing the map to place letters according to their frequenciees 
    //we will place the letters in the inputed string "s" itself
    //we will do this to avoid using extra space
    
    int index=0;//this is the index of string s
    for(int i=0;i<26;i++){//traversing the mmap
        char ch=i+'a';//retriving corresponding character from index
        while(map[i]>0){//used to place letters according to theeirr frequencies
            s[index]=ch;
            index++;
            map[i]--;
        }
    }
    return s;
}