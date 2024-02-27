class Solution {
public:

    //FUNCTION  FOR FILLING LPS TABLE
    void fill_lps(vector<int> &LPS, string &str){
        LPS[0]=0;
        int pref=0,suff=1;
        while(suff<LPS.size()){
            if(str[pref]==str[suff]){
                LPS[suff]=pref+1;
                pref++;
                suff++;
            }
            else{
                if(pref==0){
                LPS[suff]=0;
                suff++;
                }
                else{
                    pref=LPS[pref-1];
                }
            }
        }
    }

    //FUNCTION FOR SEARCHING A STRING IN MAIN STRING
    void KMPsearch(string &txt,string &pat,vector<int> &LPS,vector<int>&occurance){
        int first=0;//POINTER THAT WILL TRAVERSE ON TXT
        int second=0;//POINTER THAT WILL TRAVERSE ON PAT

        while(first<txt.size() && second<pat.size())////..........veery veery important condition................///
        {
            if(txt[first]==pat[second]){
                first++;
                second++;
                
                if(second==pat.size()){///////>>>>>>>>>VERY VERY VERY VERY VERY IMPORTANT IN THIS QUESTION <<<<<<<<<<<<<<<<////////////
                    occurance.push_back(first-second);
                    second=LPS[second-1];
                }
            }
            else{
                if(second==0){
                    first++;
                }
                else{
                    second=LPS[second-1];
                }
            }
        }
    } 

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        //SO BSICALLY WE HAVE TO SEARCH STRING A AND B IN THE STRING S AND COMPARE THE INDEXES WHERE THEY APPEAR
        //IF THOSE INDEXES SATISFY THE CONDITION THAT DIFFERENCE BETWEEN THOSE INDEXES IS LESS THAN OR EQUALS TO THE K
        //THEN I WILL PUSHBACK THE INDEX I INTO THE ANS VECTOR
        
        //FOR SEARCHING STRING A AND B IN STRING S, I HAVE TO USE KMP ALGORITHM WHICH IS THE MOST EFFICIENT ALGORITHIM FOR STRING MATCHING
        //FOR THAT AS THE FIRST STEP WE HAVE TO CREATE LPS TABLE FOR THE STRING A AND B
        //SO AS WE HAVE TO DO THE SAME WORK FOR BOTH  SO I WILL DO THAT WITH A FUNCTION
        
        vector<int> aLPS(a.size());//LPS table for string a
        fill_lps(aLPS,a);//IN FUNCTION I WILL PASS THE STRING AND ITS LPS TABLE BY REFERENCE TO FILL THAT
        vector<int> bLPS(b.size());//LPS table for string b
        fill_lps(bLPS,b);//IN FUNCTION I WILL PASS THE STRING AND ITS LPS TABLE BY REFERENCE TO FILL THAT

         //NOW THE FUNCTION WILL FILL THE LPS TABLE FOR  EACH STRING
         //SO NOW OUR WORK IS TO SEARCH ALL OCCURANCES OF BOTH STRINGS IN THE MAIN STRING S
         //WHY ALL OCCURANCES??????
         //BECAUSE ONCE WE WILL GET ALL OCCURANCES OF STRING A AND STRING B THEN WE CAN SUBSTRACT THEIR INDEX OF OCCURANCE TO CHECK WHEATHER THE INDEX IS BEAUTIFUL INDEX OR NOT
         //IF THE ABSOLUTE VALUE OF DIFFERENCEE BETWEEN  INDEX OF A NAD INDEX OF B IS LESS THAN OR EQUALS TO THE K THEN  INDEX OF OCCURANCE OF A I.E 'I' WILL BE A BEAUTIFUL INDEX

         //BUT WHY CANNOT WE FIND ONE BY ONE INDEX AND THEN COMAPRE IT???? IS IT NECESSARY TO FIND ALL OCUURANCES AND THEN COMPARE IT ????
         //YES IT IS ABSOLUTELY NECESSARY
         //BECAUSE THERE WILL BE CASE WHERE ONE INDEX 'I' WILL NOT BEE THE BEAUTIFUL INDEX WHEN COMPARED WITH ONE 'J' BUT THAT SAME 'I' WILL BE BEAUTIFFUL INDEX WHEN CHECKED WITH ANOTHER 'J'
         //THAT IS WHY WE FIRST FIND ALL OCCURANCES AND FROM THERE WE TRY ALL COMBINATIONS OF I AND J AND CHECK WHEATHER 'I' CAN BE THE BEAUTIFUL INDEX

         //SO LETS FIND ALL THE OCCURANCES OF A IN STRING S
         vector<int>a_occurance;//VECTOR THAT WILL STORE INDEXES WHERE STRING  A PRESENT IN STRING S
         KMPsearch(s,a,aLPS,a_occurance);//THIS WILL PUSHBACK ALL THE INDEXES WHERE A PRESENT (I.E 'I' )IN THE STRING S INTO THE VECTOR "a_occurance"

         //SO LETS FIND ALL THE OCCURANCES OF B IN STRING S
         vector<int>b_occurance;//VECTOR THAT WILL STORE INDEXES WHERE STRING  B PRESENT IN STRING S
         KMPsearch(s,b,bLPS,b_occurance);//THIS WILL PUSHBACK ALL THE INDEXES WHERE B PRESENT (I.E 'J' ) IN THE STRING S INTO THE VECTOR "b_occurance"
 
        //NOW LETS CHECK EACH PAIR OF I AND J TO FIND A PAIR WHICH HAVE DISTACE LESS THAT OR EQUAL TO K
        //IF WE FOUND ANY PAIR  THEN WE WILL PUSHBACK 'I' INDEX (OR THE INDEX OF OCCURANCE OF A) IN THE ANSWER VECTOR
        vector<int> ans;

        //WHEN WE WILL FIND A INDEX 'I' TO BE BEAUTIFUL THEN WE WILL PUSH THAT IN AND MOVE TO THE NEXT 'I' WE WILL NOT FURTHER CHECK FOR THE ALREADY BEAUTIFUL INDEX 
        //FOR THIS WE WILL USE BREAK STATEMENT WHEN WE WILL GET A BEAUTIFUL INDEX TO STOP FURTHER CHECKING FOR IT

        for(int m=0;m<a_occurance.size();m++){//m is the index value and this outer loop will traverse on each element of a_occurance which stores occurance of string a in string s or (i)
            for(int n=0;n<b_occurance.size();n++){ //m is the index value and this inner loop will traverse on each element of b_occurance which stores occurance of string b in string s or (j)
                 if( abs(a_occurance[m]-b_occurance[n]) <= k ){
                     ans.push_back(a_occurance[m]);
                     break;//WE WILL NOT FURTHER CHECK FOR THIS INDEX
                     //BY BREAKING THE INNER LOOP WE WILL GO FOR CHECKING THE NEXT INDEX IN "a_occurance" VECTOR
                 }
            }
        }

        return ans; //WHY WE ARE DIRECTLY RETURNING THE ANS AS IT HAS ASKED TO RETURN IT BY SORTING IT ????
        //ACTUALY WHILE WE WERE FINDING THE OCCURANCES OF A AND B THERE THE OCCURANCES WERE FOUND FROM THE BEGEINING INDEX OF STRING S
        //SO THE INDEXES THAT WERE STORED IN A_OCCURANCE AND B_OCCURANCE VECTORS WILL BE ALREADY IN SORTED MANNER
        ////AND HERE WHILE COMAPREING I AND J PAIRS THERE ALSO WE WERE TAKING I INDEXES FROM A_OCCUARANCE VECTOR FROM START TO END WHICH IS SORTED MANNER
        //FOR THUS REASON IF WE PUSH ANY INDEX INTO ANSWWER VECTOR THAT WILL BE IN SORTED ORDER 
        //DRY RUN AN EXAMPLE TO UNDERSTAND THIS IN A BETTER  MANNER

        
    }
};