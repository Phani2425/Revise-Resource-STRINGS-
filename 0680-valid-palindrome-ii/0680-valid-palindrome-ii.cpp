class Solution {
public:
//function for checking palindrome or not
    bool Palindrom(string &s,int start,int end){
        while(start<=end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                //s[i]!=s[j]
                //1 removal is allowed
                //we will remove value pointed by i and j one by one and recheck unchecked substring

                //checking remaining unchecked array after removing value pointed by i
                bool ans1=Palindrom(s,i+1,j);

                 //checking remaining unchecked array after removing value pointed by j
                 bool ans2=Palindrom(s,i,j-1);

                 //returning true if any one of both is palindrome
                 return ans1||ans2;
            }
        }
        //agar yaha tak pahunche ho then 0 removal and string originally palindrome hai
        return true;
        
    }
};