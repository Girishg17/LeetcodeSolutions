class Solution {
public:
    int candy(vector<int>& ratings) {
       vector<int>dp(ratings.size(),1);
       for(int i=1;i<ratings.size();i++){
           if(ratings[i]>ratings[i-1]){
               dp[i]=dp[i-1]+1;
           }
          
      
       }
       for(int i=ratings.size()-2;i>=0;i--){
           if(ratings[i+1]<ratings[i]){
               if(dp[i]<=dp[i+1]){
                   dp[i]=dp[i+1]+1;
               }
           }
       }
       int sum=0;
       for(auto it:dp){
           sum+=it;
       } 
       return sum;
    }
};