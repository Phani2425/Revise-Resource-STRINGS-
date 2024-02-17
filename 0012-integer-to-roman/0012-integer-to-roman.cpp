class Solution {
public:
    string intToRoman(int num) {
       vector<string> roman{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
       vector<int> value{1,4,5,9,10,40,50,90,100,400,500,900,1000};
       string ans;
       while(num>0){
           for(int i=value.size()-1;i>=0;i--){
               if(num>=value[i]){
                  ans=ans+roman[i];
                  num=num-value[i];//updating num
                  break;
               }
           }
       }
       return ans;
    }
};