class Solution {
public:
    int strStr(string haystack, string needle) {
        //ONE APPROACH
        // if(haystack.find(needle)== string::npos){
        //     return -1;
        // }
        // return haystack.find(needle);

        //ANOTHER APPROACH
        // for(int i=0;i<haystack.length();i++){
        //     string sub=haystack.substr(i,needle.length());
        //     if(sub.compare(needle)==0){
        //         return i;
        //     }

        // }
        // return -1;

        //MOST OPTIMAL APPROACH
        //KMP ALGORITHM

        //FOR IMPLEMENTATIONN OF KMP ALGORITHM WE NEED TO FIRST MAKE AND FILL THE LPS TABLE FOR NEEDLE
        //SO LETS BUILD THAT FIRST
        //size of needle
        int k=needle.size();
        vector<int> lps(k);
        lps[0]=0;
        int pref=0,suff=1;
        while(suff<k){
            if(needle[pref]==needle[suff]){
               lps[suff]=pref+1;
               pref++;
               suff++;
            }
            else{
               if(pref==0){
                   lps[suff]=0;
                   suff++;
               }
               else{
                   pref=lps[pref-1];
               }
            }
        }

        //WE HAVE BUILT THE LPS NOW  WE HAVE TO ONLY TRAVERSE THE STRING HAYSTACK
        //DECLARING POINTERS 
        int first=0;//it will traverse haystack and will always move forward
        int second=0;//this will traverse needle and can move backward

        while(second<k && first<haystack.size()){ //here we are using both conditions because:- 
        //here we are traversing two strings whre first is used to traverse haystack and second is used to traverse needle
        //so in the cases where needle is present in te haystack such as:- haystack=cabcde and needle=abc
        //in this case second will go out of bound first and here we have to stop the loop 
        //but in the cases in which needle is not present in the haystack such as:- haystack=ddddddddc nad needle=abc 
        //in these cases first will go  out of bound first while second will bee at 0th index of needle
        //SO TO HANDLE BOTH THE CASES WE HAVE INCLUDED BOTH CONDITIONS WHICH STATES WHEN EVEN A SINGLE POINTER AMONG FIRST AND SECOND GOES OUT OF BOUND THEM WE WILL STOP THE LOOP
            if(haystack[first]==needle[second]){
                first++;
                second++;
            }
            else{
                if(second==0){
                    first++;
                }
                else{
                    second=lps[second-1];
                }
            }
        }

        //ETHI AME SECOND SETEBELE INCREMENT KARUCHE JETEBELE (haystack[first]==needle[second]) HAUCHI 
        //SO JADI LOOP END HELA PARE SECOND OUT OF BOUND JAITHIBA TA MANE HAUCHU KI NEEDLE RA ALL CHARACTER HAYSTACK CHRACTERS SHA MATCH KARIJAICHI 
        //SETHI  PAIN SECOND POINTER INCREMENT HEI HEI KI OUT OF BOUND GALA 
        //THIS INDIRECTLY MEANS KI NEEDLE , HAYSTACK BHITARE PRESENT ACHI

        if(second==k){ //SECOND K-1 RE THILA THEN ++ HEIKI K RE PAHANCHITHIBA AU THEN CONDITION PAIN  LOOP BREAK HEIJAITHIBA
           return first-second;
        }
        else{//MEANS JADI SECOND OUT OF BOUND HEINI TATHAPI LOOP BREAK HELA TA MANE FIRST POINTER OUT OF BOUND HEIJAICHI
        //AU JADI FIRST OUT OF BOUND HEICHI TA MANE  NEEDLE, HAYSTACK RE PRESENT NAHI SO RETURN -1
            return -1;
        }

        
    }
};