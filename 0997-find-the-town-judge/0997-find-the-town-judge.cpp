class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //agar pure gaon me ek hi log hai to na wo kisipe trust karega no koi uspe karega so wohi judge ho sakta hai
        if(n==1){
            return 1;
        }
        //agar gaon be 1 se jyada log hai par ksisme trust nehi hai to iska matlab koi judge nehi hai
        if(trust.empty()){
            return -1;
        }


        //vector that in which if any index have value equal to n-1 then we will return that index+1 which wii mean that index+1 will be that person on which everyone on the town trusts
        //if any person trusts any one we will decrement value int the corresponding index of that person
        //as here we are creating n sized vector having last index as n-1 hence we will store value of n in n-1 index
        vector<int> people(n,0);

        //counting no of rows in trust vector
        int row=trust.size();
        //counting no of columns
        int col=trust[0].size();

        //traversing through each element
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){

                if(j==0){
                    people[(trust[i][j]-1)]--;//this means that the person present at col index 0 will be trusting someone henece we will do -1 in it's corresponding index as he cannot be judge 
                }
                if(j==1){
                    people[(trust[i][j]-1)]++;//this means that the person present at col index 1 is trusted by someone that means he has a chance of being judge so we will increment its value by 1
                }
            }
        }

        //traversing the people vector
        for(int i=0;i<n;i++){
            if(people[i]==n-1){//if any people have everyones trust except himself....this means trust of n-1 peoples
                return i+1;//we are doing i+1 as we were storing value at (people-1)th index
                //by returning i+1 we can get the people
            }
        }
        return -1;
    }
};