class Solution {
public:
    string defangIPaddr(string address) {
        //declaring ans string
        string ans;

        for(char ch:address){
            if(ch=='.'){
                ans+="[.]";
            }
            else{
                ans+=ch;
            }
        }
        return ans;

        
    }
};