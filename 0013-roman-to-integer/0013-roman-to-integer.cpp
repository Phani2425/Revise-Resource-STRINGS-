class Solution {
public:

    //function that will convert roman its corresponding integer value
    int intvalue(char ch){
        vector<char> roman{'I','V','X','L','C','D','M'};
        vector<int> value{1,5,10,50,100,500,1000};

        for(int i=0;i<roman.size();i++){
            if(ch==roman[i]){
                return value[i];
            }
        }
        return 0;
    }

    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.size()-1;i++){//here we have taken limit of i upto lastindex-1 because inside this loop 
        //we are going to compare a character to its next index character hence if we will go upto size-1
        //i.e last index then we willl be trying to access out of bound index which will throw error

        if(intvalue(s[i])>=intvalue(s[i+1])){
            ans=ans+intvalue(s[i]);
        }
        else{
            ans=ans-intvalue(s[i]);
        }

        }
        ans=ans+intvalue(s[s.size()-1]);
        return ans;
    }
};