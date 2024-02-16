class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        int size=s.length();
        int i=0,j=0;
        int count=0;
        while(j<size){
            if(isdigit(s[j])){
              string temp=s.substr(i,j-i+1);
              int pos=temp[temp.size()-1]-'0';
              temp.pop_back();
              ans[pos]=temp;
              count++;
              j+=2;
              i=j;
            }
            else{
                j++;
            }
        }

        s.clear();
        for(int i=1;i<=count;i++){
            if(i<count){
                s=s+ans[i];
                s.push_back(' ');
            }
            else{
                s=s+ans[i];
            }
        }
        return s;
        
        
    }
};