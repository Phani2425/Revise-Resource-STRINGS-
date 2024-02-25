
//QUESTION HAS ASKED TO SOLVE IT USING KMP ALGORITHM BUT I HAVE TRIED TO SOLVE IT USING SLIDING WINDOW TECHNIQUE

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
        //FUNCTION TO CHECK WHEATHER THE CURRENT WINDOW HOLDS ALL ELEMENT OF 'PAT' WITH SAME FREQUENCY AS 'PAT'
            //AS WE HAVE MAPPED THE FREQUENCY OF CHARACTERS OF 'PAT' AND WHEN EVER A CHARACTER ENTERS INTO OUR WINDOW WE ARE REDUCING ITS FREQUENCY IN MAP
            //SO IF THE WINDOW WILL HAVE ALL CHARACTERS WITH SAME FREQ AS 'PAT' THE IN MAP ALL VALUES WOULD BE REDUCED TO ZERO
            //SO HERE WE WILL ONLY CHECK WHEATHER ALL VALUES IN MAP ARE ZERO OR NOT 
            //IF ALL ARE ZERO THEN CURRENT WINDOW IS EQUAL TO PAT ELSE NOT
            bool all_freq_zero(vector<int>&map){
                for(int freq:map){
                    if(freq!=0){
                        return false;//agar kisi bhi character ka freq zero nehi hai to false return kardo
                    }
                }
                return true;//aur agar loop khatam ho gaya aur kuch return na hua to true  return kardo
            }
    
        vector <int> search(string pat, string txt)
        {
            //code here
            //LETS TRY IT WITH SLIDING WINDOW TECHNIQUE
            //AS THAT IS THE TECHNIQUE WHICH CAN BE USED THE TO SOLVE PREOBLEMS RELATED TO SUBSTRING OR SUBBAARAY
            
            //LETS US FIRST  MAP THE 'PAT' STRING WHICH WILL HELP US FURTHER
            //MAPPING THE 'PAT'
            vector<int> map(26,0);
            for(char ch: pat){
                map[ch-'a']++;
            }
            //NOW THE 'PAT' IS MAPPED
            
            //NOW WE WILL BE NEEDING A ANS VECTOR WHERE WE CAN PUT OUR INDEXES WHERE 'PAT' IS PRESENT IN STRING 'TXT'
            vector<int>  ans;
            
            //NOW WE WILL DECLARE TWO POINTERS WHICH WILL ACT AS TWO BOUNADARY OF THE SLIDING WINDOW
            //INITIALLY BOTH POINTERS  WILL BE AT SAME  POSITION SO THE WINDOW SIZE WILL BE 1 INITIALLY
            //UNTILL THE ACHIVE THE WINDOW SIZE SAME AS THE SIZE OF 'PAT' WE WILL ONLY MOVE THE RIGHT BOUNDARY OR POINTER
            //ONCE WE GOT OUR WINDOW SIZE SAME AS THE SIZE OF 'PAT'  THEN OUR WORK IS TO SLIDE THAT WINDOW AND SEE WHEATHER THE SUBSTRING PRESENT IN THE  WINDOW IS MATCHING OUR PAT
            //WE WILL CONTINUE THIS UNTILL THE RIGHT BOUNDARY OR RGHT POINTER GOES OUT OF BOUND OR CROSSES THE LAST INDEX OF TXT
            
            //SIZE OF PAT
            int k=pat.length();
            //DECLARING THE POINTERS
            int left=0,right=0;
            
            //TO ACHIVE THE SAME SIZE AS 'PAT' FIRST WE WILL MOVE OR INCREMENT 'RIGHT' POINTER AS THAT HAS MORE CHANCE OF GOING OUT OF BOUND
            //SO WE WILL USE A CONDITION HERE TO CONTINUE THE SLIDING AND CHECKING UNTILL ('RIGHT'<TXT.SIZE())
            while(right<txt.length()){
                //decreasing the frequency of character in map as it is in the window now
                map[txt[right]-'a']--;
                
                //IF WINDOW HAVE SAME SIZE AS PAT
                if(right-left+1 == k){
                    if(all_freq_zero(map)){
                        ans.push_back(left+1);//AS IT HAS ASKED TO USE 1 BASE INDEXING WHILE PUSHING INDICES SO WE ARE PUSHING (LEFT+1)
                    }
                    
                    //MOVING THE WINDOW
                    //TO MOVE THE WINDOW WE WILL MOVE BOTH LEFT AND RIGHT POINTER
                    //SO WHEN WE ARE MOVING THE LEFT POINTER WE ARE EXCLUDING A CHARATER FROM THE WINDOW
                    //WHIILE INCLUDING THAT WE DECREASED ITS FREQUENCY FROM THE MAP TO SHOW THAT THE CHARACTER IS CURRENTLY IN THE WINDOW
                    //SO BEFORE MOVING THE LEFT  POINTER OR BEFORE EXCLUDING A CHARACER WEE HAVE TO INCREASE ITS FREQUENCY IN THE MAP
                    map[txt[left]-'a']++;
                    left++;
                    //moving right to achive same size as 'pat' again
                    right++;
                }
                else{
                    right++;
                }
            }
            
            if(ans.size()==0){//if ans has no element or ans have 0 size this means pat is not present in txt ..... so we  will return  -1 before that we have to push back -1 to ans
            //as the return typpe of thee fuction is vector so we have  to return vector
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
