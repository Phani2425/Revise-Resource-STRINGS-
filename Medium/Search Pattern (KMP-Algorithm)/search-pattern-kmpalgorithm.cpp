//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    //FUNCTION FOR FILLING THE LPS TABLE OF PAT
    //THIS WILL RECIEVE THE LPS BY REFERENCE AND MAKE IN PLACE CHANGES TO AVOID EXTRA SPACE USAGE
    //THIS WILL HAVE A VOID RETURN TYPE AS THIS WILL NOT RETURN ANYTHING JUST FILL VALUES IN THE LPS VECTOR
    
    void fill_LPS(vector<int> &LPS, string pat){
        //program for filling lps table
        LPS[0]=0;
        //declaring pointers
        int pref=0,suff=1;
        
        while(suff<LPS.size()){//until the LPS is filled upto  the lat index
            
            if(pat[pref]==pat[suff]){
                
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
    
    
        vector <int> search(string pat, string txt)
        {
            //code here
            
            //KMP ALGORITHM
            
            //FOR MORE UNDERSTANDING ON KMP ALGO REFER TO THE NOTES (DSA-1 AND DSA-2 NOTES)
             //TIME COMPLEXITY:- O(N)  >..... AS WE ARE TRAVERSING THE STRING NEARLY ONCE
             //SPACE COMPLEXITY:- O(N)  >>>>>>>> DUE TO CREATION OF LPS TABLE OR VECTOR HAVING SAME SIZE AS STRING
            //FOR DEPLOYMENT OF KMP ALGORITHIM THE FIRST STEP IS CONSTRUCTING LPS(LONGEST PREFIX SUFFIX) TABLE FOR A STRING WHICH WE ARE TRYING TO FIND INA ANOTHER STRING
            //SO LETUS CONSTRUCT THAT FIRST
            vector<int>LPS(pat.length());
            
            //FOR FILLING UP THIS VECTOR WE CAN DO IT HERE OR WE CAN CREATE A  SEPARATE FUNCTION TO DO THAT
            //IF WE WILL CREATE A SEPARATE  FUNCTION THEN WE HAVE MAKE IN PLACE CHAGES IN THE LPS VECTOR SO WE HAVE TO PASS THAT BY REFERENCE
            //CALLING THE FUNCTION TO FILL UP THE LPS TABLE
            fill_LPS(LPS,pat);
            
            //NOW LPS IS FILLED
            
            //WE WILL START  COMPARING TXT AND PAT CHARACTER BY CHARACTER
            //DECLARING POINTER TO COMPARE
            int first=0,second=0;//FIRST WILL TRAVERSE TXT AND SECOND WILL TRAVERSE PAT
            
            //CREATING VECTOR THAT WILL STORE THE  INDICES WHERE PAT IS PRESENT IN TXT
            //ALSO WE HAVE TO KEEP IN NOTE THAT IT HAS ASKED TO ASSUME TXT HAS 1 BASED INDEXING
            // SO WHILE PUSHING ANY INDEX WE HAVE TO PUSH IT BY DOING (INDEX+1) TO SATIFY THE GIVEN ASSUMPTION
            vector<int> ans;
            
            while(first<txt.length()){//THIS IS THE MOST IMPORTANT PART
            //HERE WE ARE TAKING A SINGLE CONDITIO BECAUSE WE HAVE TO RETURN INDICES OF ALL OCCURANCES OF PAT IN TXT
            //WHICH MEANS WE HAVE TO CHECK WHOLE TXT STRING HENCE WE WILL CHECK UNTILL FIRST POINTER GOES OUT OF BOUND
            //WHENEVER SECOND POINTER WILL GO OUT OF BOUND THERE WE WILL MAKE IT START FROM 0TH INDEX OF PAT AGAIN UNTILL WE SEARCH THE COMPLETE TXT STRING
            
            if(txt[first]==pat[second]){
                first++;
                second++;
                
                //THIS IS THE ONLY REGION WE INCREMENT SECOND POINTER SO HERE WE HAVE TO CONTINUOUSLY CHECK WHEATHER SECOND POINTER IS INSIDE THE BOUND OR NOT
                //IF IT GOES OUT OF BOUND THAT WILL MEAN THAT WE HAVE GOT A SUBSTRING IN TXT WHICH MATCHES WITH PAT SO WE WILL GET THE 
                //INDEX WHERE THAT SUBSTRING STARTS BY DOING (FIRST-SECOND)
                //THEN AS WE HAVE NOT CHECKED THE WHOLE STRING HENCE WE WILL AGAIN BRING BACK THE SECOND POINTER TO 0TH INDEX OF PAT FOR FURTHER CHECKING IN REMAINING PART OF TXT STRING
                
                if(second==pat.length()){//AGAR SECOND PAT KA LAST INDEX CROSS KARGAYA TO
                    int index=first-second;//THIS IS THE 0 BASED INDEX OF TXT WHERE PAT IS PRESENT
                    ans.push_back(index+1);//pushed 1 based index
                    
                    //NOW BRINGING SECOND BACK TO 0TH INDEX OF PAT 
                    second=0;
                    
                    //EDGE CASE
                    
                    // HERE WE BOUGHT BACK SECOND TO 0 BUT LET FIRST REMAIN THERE AS PER ACTUAL KMP ALGORITHM
                    //BUT IN THOSE QUESTION WE HAD TO ONLY RETURN THE INDEX OF FIRST OCCURANCE OF PAT IN TXT THAT IS WHY WE NNED NOT TO BRING FIRST BACK
                    //BUT THERE ARE SOME CASES WHERE IF WE DONOT BRING BACK FIRST WE WILL MISS SOME INDEX WHERE PAT CAN BE PRESENT IN THE TXT
                    //FOR EXAMPLE:- TXT= "AAAAAA" AND PAT="AAA"
                    //HERE THE ACTUAL OUTPUT SHOULD BE:- 0,1,2,3 IN 0 BASED INDEXING AND 1,2,3,4 IN 1 BASE INDEXING
                    //BUT ACCORDING TO OUR LOGIC IF WE DO NOT BRING BACK 'FIRST' THEN WE WILL GET OUTPUT AS:- 0,3 IN 0BASE INDEXING AND 1,4 IN 1 BASED INDEXING
                    //BECAUSE WHEN WE WILL GET THAT AT INDEX 0 OF TXT STRING, PAT IS PRESENT THEN OUR FIRST WILL BE AT 3RD INDEX AND SECOND WILL BOUGHT BACK TO 0TH INDEX
                    //NOW COMPARISION WILL START FROM 3RD INDEX OF TXT SO WE WILL MISS 1ST AND 2ND INDEX
                    //SO WE HAVE TO BRING BACK FIRST TO THE NEXT INDEX WHERE WE GOT OUR PAT
                    
                    first=index+1;
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
          
          if(ans.size()==0){//if ans has no element or ans have 0 size this means pat is not present in txt ..... so we  will return  -1 before that we have to push back -1 to ans
            //as the return type of thee fuction is vector so we have  to return vector
                ans.push_back(-1);
            }
            
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends