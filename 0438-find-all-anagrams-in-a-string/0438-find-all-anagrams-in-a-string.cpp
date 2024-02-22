class Solution {
public:

    //writing function which will check wheather every index in map have 0 value or not
    int allzero(vector<int> &map){
        for(int &freq : map){
            if(freq != 0){
                return 0;//agar ek bhi index ka value 0 se equal na hua to iska matlab hai ki abhi ka window anagraam nehi hai
            }
        }
        return 1;//agar loop khatam ho gaya aur kuch return nahua to iska matlab ye hai ki map ke sare index me value 0 hai
    }

    vector<int> findAnagrams(string s, string p) {
        //we will be using sliding window technique here to check for all possible substring present in the txt having same length as pat
	    //but if we try to find out all possible substrings in the given string then that will take O(n^3) time
	    //so to optimise this we will  traverse the string only once and try to find and count the anagrams
	    //so for finding substring having same size as pat we have to first find the size of string p
        int psize=p.length();
        	    //then as we will be traversing the txt string with the help of two pointers hence we will be requiring the length of txt string
	    int ssize=s.length();
        //creating vector which will store the first index of all anagrams
        vector<int> ans;

        //before traversing the string s for finding anagram of p, we have to map the occurance of characters of p so that when ever we will have all those characters with the samefrequency as p in our current window or current substring that will
	    //mean that our current window is a possiblee anagram of the p
	    //so we will push first index of that window or substring into ans vector
	    
	    //for mapping we will be needing a vector of 26 size as p have any lowercase english letters as per the question
	    vector<int> map(26,0);
	    //trversing the pat for mapping purpose
	    for(char &ch : p){
	        map[ch-'a']++;
	    }

         //declaring pointers and initialising them from 0th index of s string
	    int i=0,j=0;

        while(j<ssize){
             //as now we have character pointed by j in our window so we will decrease the count of that from map
            map[s[j]-'a']--;

            if(j-i+1==psize){//if size of our current window is same as the size of p then this substring present in this window is the perfect candidate to be the anagram 
	        //so we will check wheather this is the anagram if yes then we will pushback its first index if no then we will move further
	        //so how will we check?????
	        //THIS IS THE TRICKY PART HERE
	        //REMEMBER WE INITIALISED EVERY INDEX OF MAP WITH 0 IN START
	        //THEN WE INCREMENTED SOME INDEXES WHILE MAPPING THE FREQUENCY OF CHARACTERS OF STRING P
	        //THIS MEANS IF OUR WINDOW WILL HAVE SAME CHARACTERS WITH SAME FREQUENCY AS PRESENT IN P THEN VALUE AT THEIR CORRESPONDING INDEX OF MAP WOULD BE 0
	        //BUT IF THE WINDOW DOESN,T HAVE EVEN ANY SINGLE CHARCTER OF PAT THEN FREQUENCY OF THAT CHARACTER WILL NOT BE 0 IN MAP
	        //ALSO IF OUR WINDOW HAVE ANY COMPLETELY DIFFERENT CHARACTER THAT THE CHARACTERS OF PAT THEN OCCURANCE OF THAT CHARACTER IN MAP WILL BE IN NEGATIVES AS INSTARTING THEIR VALUE WAS INITIATED WITH 0
	        //SO FROM ALL THIS WE CONCLUDE THAT IF FOR A CERTAIN WINDOW, VALUES AT ALL INDEXES OF MAP IS 0 THEN THAT WINDOW IS A ANAGARM OF P
	        
	        //SO WE WILL  CALL A FUNNCTION WHICH WILL CHECK WHEATHER FOR CURRENT WINDOW ALL INDEX OF MAP HAVE VALUE 0

                if(allzero(map)){
                    ans.push_back(i);//pushing starting index of the current window into ans vector
                }

            //now as we got the same size window as p so we will now move the window by moving i
	        //as we are moving i forward , we are excluding a character from current window so
	        // before moving i we have increse its occurance value in map as whilee taking it into the window with j we decrementeed its occurance in map
                map[s[i]-'a']++;
                //moving i forther
                i++;
            }
            j++;//yaha j hamesa age badhta rahega agar hame p size ka window milgaya tab jake i ko age layenge 
        }

        return ans;
    }
};