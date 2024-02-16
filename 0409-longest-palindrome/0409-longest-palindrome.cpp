class Solution {
public:
    int longestPalindrome(string s) {
        //creating 2 separate vectors for mapping lower case and upper case charaterss separately
        vector<int> lowercase(26,0);
        vector<int> uppercase(26,0);
        
        //if character is lower case then it will be mapped in lowercase vetor 
        //else it will be mapped in uppercase vector
        for(char ch:s){
            if(ch>='a'){
                lowercase[ch-'a']++;
            }
            else{
                uppercase[ch-'A']++;
            }
        }

        //creating a variable which will store our ans that  is length of longrst possible palindrome
        int count=0;
        //this  flag variable will tell us if there is any odd occuring chhharacter
        //if there is any odd occuring character then that will be used to make odd palindrome 
        //so flag will be added to count at last while returning
        //if there will be no odd occuring element then flag will be 0 else flag will be 1
        int flag=0;

        //once  mapping is finished we will traverse through through both vector
        //to check the occurances of chracter
        //if character occurance is even then we can include all its occurances in the longest palindrome
        //if occurance is odd then we can include onnly even part which is (occcurance-1) in the longest palindrome
        for(int i=0;i<26;i++){
            if(lowercase[i]%2==0){
                count=count+lowercase[i];//i can take all its occurances to make longeest palindrome as its occurance is even
            }
            else{
                count=count+lowercase[i]-1;//if odd then i can taake only its even part
                flag=1;
            }
            if(uppercase[i]%2==0){
                count+=uppercase[i];
            }
            else{
                count+=uppercase[i]-1;
                flag=1;
            }
        }
        return count+flag;
        
    }
};