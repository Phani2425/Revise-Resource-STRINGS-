class Solution {
public:
    string makeGood(string s) {
        int i=0,j=1;
        while(j<s.length()){
            if(s[i]>='a'&&s[i]<='z'&&s[j]>='a'&&s[j]<='z'){
                i++;
                j++;
            }
            else{
                if(s[i]==(s[j]+'a'-'A') || s[j]==(s[i]+'a'-'A')){
                     s.erase(i,2);
                     i=0;
                     j=1;
                }
                else{
                    i++;
                    j++;
                }

            }
        }
        return s;
    }
};