class Solution {
public:

   bool checkfrequency(string s){
       vector<int> map(26,0);
       for(char ch:s){
           map[ch-'a']++;
       }
       for(int i:map){
           if(i>1){
               return true;
           }
       }
       return false;
   }

    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }

        if(s==goal){
            return checkfrequency(s);
        }

        vector <int> diff;
        for(int i=0;i<s.length();i++){
            if(s[i] != goal[i]){
                diff.push_back(i);
            }
        }

        if(diff.size()!=2){
            return false;
        }
        else{
            swap(s[diff[0]],s[diff[1]]);
            return (s==goal);
        }
    }
};