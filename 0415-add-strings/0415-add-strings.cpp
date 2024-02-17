class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum;
        int  i=num1.size()-1;
        int j=num2.size()-1;
        int num,carry=0;
        char ch;
        while(i>=0 && j>=0){
            num=(num1[i]-'0')+(num2[j]-'0')+carry;
            ch=num%10 + '0';
            sum.push_back(ch);
            carry=num/10;
            i--;
            j--;
        }
       if(max(i,j)==i){
           while(i>=0){
               num=carry+(num1[i]-'0');
               ch=num%10+'0';
               sum.push_back(ch);
               carry=num/10;
               i--;
           }
       }
       else{
           while(j>=0){
                num=carry+(num2[j]-'0');
               ch=num%10+'0';
               sum.push_back(ch);
               carry=num/10;
               j--;
           }
       }
       if(carry!=0){
           sum.push_back(carry+'0');
       }
       reverse(sum.begin(),sum.end());
       return sum;
    }
};