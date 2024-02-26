class Solution {
public:

    bool is_palindrome(string s,int start,int end){
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
        int start=0,end=s.length()-1;
        while(start<=end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                //ek baar start pointed character ko hatake dekhenge
                if(is_palindrome(s,start+1,end)==true){
                    return true;
                }

                //phir end pointed character to hatakee dekhenge
                else if(is_palindrome(s,start,end-1)==true){
                    return true;
                }

                else{
                    return false;
                }
            }
        }

        return true;
    }
};