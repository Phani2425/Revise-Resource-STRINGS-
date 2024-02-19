class Solution {
public:
    int compress(vector<char>& chars) {

        if(chars.size()==1){
            return 1;
        }

        int count=1;
        string str;//it ewill be used to strore when count will be converted into string
        int index=0;//this will indicate the index of chars array as using this we will direct put the character in to char array
        for(int i=0;i<chars.size()-1;i++){
            if(chars[i]==chars[i+1]){
                count++;
            }
            else{
                chars[index]=chars[i];
                index++;
                if (count > 1) {
                // Convert the count to a string and append it digit by digit
                str=to_string(count);
                for(char ch:str){
                    chars[index]=ch;
                    index++;
                }
                }
                count=1;
            }
        }
          int n=chars.size()-1;
        if(chars[n]==chars[n-1]){
                
                    chars[index]=chars[n];
                    index++;
                    str=to_string(count);
                    for(char ch:str){
                    chars[index]=ch;
                    index++;
                    }
                     
               }
        else{
                    chars[index]=chars[n];
                    index++;
                }  
                

        return index;//this is the most  important point 
        //here we can notice that we are not completely editing the chars array we are just edititng the chars array upto a certain index
        //for example we are edititng the chars array of given 1st example only upto its 5th index
        //other indexes will be same as they are
        //whatever value we will return here compiler will check only that size of char array
        //if we return 5 then it will check from 0 to 4th index of array i.e subaary of 5 size
        //if we return 6 then it will check  6 sized subarray starting from 0 index to 5th index
        //so here we will return the size of our edited array
        //and that size will always be 1 larger than the index upto which we edited as this is a 0 indexed array
        //hence as we are editing the array using "index" and every time we edit something index++ happens
        //hence at last it can give us our size of edited array
    }
};