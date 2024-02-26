int Solution::solve(string A) {
    
    //THIS IS A SIMILLAR QUESTION LIKE THE QUESTION WHERE  IT HAS ASKED TO RETURN MINIMUM CHARACTERS REQUIRED TO ADD IN FRONT OF A STRING TO MAKE IT PALINDROME
    //HERE IT HAS ASKED TO ADD CHARACTERS AT BACK OF THE STRING
    //THIS MEANS HERE WE HAVE TO FIND THE LENGTH  OF THE LONGEST SUFFIX PALINDROME IN THE STRING
    //ONCE I FOUND THAT I CAN SUBSTRACT THAT LENGHT FROM TTHE TOTAL SIZE OF THE  STRING TO GET THE NO OF REMAINING CHARACTERS
    //THAT IS THE NO OF CHARACTERS TO BE APPENDED AT END OF THE STRING TO MAKE STRRING A a PALINDROME
    
    //LETS DO THIS
    
    string rev=A;
    reverse(rev.begin(),rev.end());
    rev=rev+'$'+A;
    
    //making lps table for rev
    vector<int>lps(rev.size());
    lps[0]=0;
    int pref=0;
   int suff=1;
   
   while(suff<lps.size()){
       if(rev[pref]==rev[suff]){
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
   
   //SO NOW THE LENGTH OF LONGEST SUFFIX PALINDROME IS
   
   int LSP=lps[lps.size()-1];
   
   int minimum=A.size()-LSP;
   
   return minimum;
    
}
