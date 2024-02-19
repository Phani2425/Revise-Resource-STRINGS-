class Solution {
public:
    int compress(vector<char>& chars) {

        if(chars.size()==1){
            return 1;
        }

        int count=1;
        string ans;
        int i;
        for( i=0;i<chars.size()-1;i++){
            if(chars[i]==chars[i+1]){
                count++;
            }
            else{
                ans.push_back(chars[i]);
                if (count > 1) {
                // Convert the count to a string and append it digit by digit
                ans=ans+to_string(count);
                }
                count=1;
            }
        }
          int n=chars.size()-1;
        if(chars[n]==chars[n-1]){
                
                    ans.push_back(chars[n]);
                    ans=ans+to_string(count);
               }
        else{
                    ans.push_back(chars[n]);
                }  
                

        int index=0;
        for(char ch:ans){
           chars[index]=ch;
           index++;
        }
        return ans.size();
    }
};