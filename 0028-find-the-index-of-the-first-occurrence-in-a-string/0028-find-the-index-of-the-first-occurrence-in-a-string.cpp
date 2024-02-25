class Solution {
public:
    int strStr(string haystack, string needle) {
        //ONE APPROACH
        // if(haystack.find(needle)== string::npos){
        //     return -1;
        // }
        // return haystack.find(needle);

        //ANOUTHER APPROACH
        for(int i=0;i<haystack.length();i++){
            string sub=haystack.substr(i,needle.length());
            if(sub.compare(needle)==0){
                return i;
            }

        }
        return -1;

        
    }
};