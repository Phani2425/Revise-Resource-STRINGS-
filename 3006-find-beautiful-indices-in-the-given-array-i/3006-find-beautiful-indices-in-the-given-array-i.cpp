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
        
        if(txt==pat){//no requirement to further comapre
            occurance.push_back(0);
            return;
        }

        int first=0;//POINTER THAT WILL TRAVERSE ON TXT
        int second=0;//POINTER THAT WILL TRAVERSE ON PAT

        while(first<txt.size())////..........veery veery important condition................///
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
        
        //but this nested loop will take 0(n^2) time complexity where n is the size of a_occurance and b_occurace
        // for(int m=0;m<a_occurance.size();m++){//m is the index value of a_occurance vector and this outer loop will traverse on each element of a_occurance which stores occurance of string a in string s or (i)
        //     for(int n=0;n<b_occurance.size();n++){ //n is the index value of b_occurance vector and this inner loop will traverse on each element of b_occurance which stores occurance of string b in string s or (j)
        //          if( abs(a_occurance[m]-b_occurance[n]) <= k ){
        //              ans.push_back(a_occurance[m]);
        //              break;//WE WILL NOT FURTHER CHECK FOR THIS INDEX
        //              //BY BREAKING THE INNER LOOP WE WILL GO FOR CHECKING THE NEXT INDEX IN "a_occurance" VECTOR
        //          }
        //     }
        // }

        //>>>>>>>>>>>>>>>>>>THIS APPROACH IS CORRECT FOR CHECKING WHEATHER I IS BEAUTIFUL INDEX OR NOT BUT THIS LEADS THE TIME COMPLEXITY TO O(N^2)<<<<<<<<<<<<<//////
    //SO LETS TRY ANOTHER APPROACH WHICH IS MORE EFFICIENT THAN THIS NESTED LOOP APPROACH AND A LITLLE BIT TRICKY
    //IF YOU WOULD THINK ABOUT THAT APPROACH THEN REALLY YOU WILL BE AMAZED 
    //SO DRY RUN THAT APPROACH YOU WILL GET VERY GOOD KNOWLRDGE
    //AS WE KNOW THAT BOTH A_OCCURANCE AND B_OCCURANCE ARE SORTED ALREADY
    // WHILE FINDING THE INDEX OF OCCURANCES OF A OR B INN STRING S WE WERE SEARCHING FOR INNDEX FROM 0TH INDEX OF STRING S TO LAST INDEX
    //SO OBVIOUSLY WE WOULD GOT THEIR INDEX OF OCCURANCE IN ASCENDING ORDER ASLO WE WILL STORE THEM IN ASCENDING ORDER IN RESPECTIVE VECTORS
    //SO LETS USE THIS SPECIALITY TO DO THE SAME STEPS BUT IN A OPTIMISED MANNER
    //WE WILL USE A TWO POINTER APPROACH TO ITERATE ON BOTH VECTOR


    int i=0;//iterate upon a_occurance
    int j=0;//itarate upon b_occurance
    while(i < a_occurance.size() && j < b_occurance.size()){
          if(abs(a_occurance[i]-b_occurance[j]) <= k){
              ans.push_back(a_occurance[i]);
              i++;
          }
          else if(a_occurance[i] > b_occurance[j]){//JADI DIFFERENCE K THU ADHIKA AU a_occurance[i] ,  b_occurance[j] THU ADHIKA SO K DIFFERENCE ACHIVE KARIBA PAIN 
          //AMAKU b_occurance[j] RA VALUE BADHEIBAKKU PADIBA SO J KU NEXT KU MOVE KARIBAKU PADIBA KAIN NA B_OCCURANCE ASSCENDING ORDER RE ACHI
              //for value at i, j may present in right of b_occurance
              j++;
          }
          else if(a_occurance[i] < b_occurance[j]){//JADI DIFFERENCE K THU ADHIKA AU a_occurance[i] ,  b_occurance[j] THU KAM ACHI SO K DIFFERENCE ACHIVE KARIBA PAIN 
          //AMAKU a_occurance[j] RA VALUE BADHEIBAKKU PADIBA SO I KU NEXT KU MOVE KARIBAKU PADIBA KAIN NA A_OCCURANCE ASSCENDING ORDER RE ACHI
              //for value at j, i may be present at right of a_occurance 
              i++;
          }
    }

    //EXPLANATION:-
//  - nested loop re taku two pointer approach re convert karideli using 'i' and 'j' jouthare i a_occurance au j b_occurance tankara current position ku represent karuchi
// -eithare di ta ja aau b_occurance sorted jouta efficient traversal ku lead kariba
// -while loop continue kariba jou parjanta di ta jaka vector re element thibe compare kariba pai (i < a_occurance.size() and j < b_occurance.size()).
// - aita check  karuchi ki current elements (a_occurance[i] and b_occurance[j]) <= k
// - ta comparision result ku neiki aita either a_occurance ku ans vector saha add kariba au i ku increment kare kimba increment kare i or j value comparision upare base kare.

     

        return ans; //WHY WE ARE DIRECTLY RETURNING THE ANS AS IT HAS ASKED TO RETURN IT BY SORTING IT ????
        //ACTUALY WHILE WE WERE FINDING THE OCCURANCES OF A AND B THERE THE OCCURANCES WERE FOUND FROM THE BEGEINING INDEX OF STRING S
        //SO THE INDEXES THAT WERE STORED IN A_OCCURANCE AND B_OCCURANCE VECTORS WILL BE ALREADY IN SORTED MANNER
        ////AND HERE WHILE COMAPREING I AND J PAIRS THERE ALSO WE WERE TAKING I INDEXES FROM A_OCCUARANCE VECTOR FROM START TO END WHICH IS SORTED MANNER
        //FOR THUS REASON IF WE PUSH ANY INDEX INTO ANSWWER VECTOR THAT WILL BE IN SORTED ORDER 
        //DRY RUN AN EXAMPLE TO UNDERSTAND THIS IN A BETTER  MANNER

        
    }
};