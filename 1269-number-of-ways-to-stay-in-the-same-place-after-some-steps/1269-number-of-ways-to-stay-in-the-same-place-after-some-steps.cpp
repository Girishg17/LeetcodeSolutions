class Solution {
public:
    int solve(int steps,int arr,int step,int i,vector<vector<long long>>&dp ){
        if( i<0 || i>=arr)return 0;
        if(step==steps){
            if(i==0){
                return 1;
            }
            return 0;
        }
        if(dp[step][i]!=-1)return dp[step][i];
        long long ans=0;
       
        ans=ans+solve(steps,arr,step+1,i+1,dp);
      
        ans=ans+solve(steps,arr,step+1,i-1,dp);
       
        ans=ans+solve(steps,arr,step+1,i,dp);
        return dp[step][i]= ans%1000000007;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<long long>>dp(steps+1,vector<long long>(steps+1,-1));

      return  solve(steps,arrLen,0,0,dp);
      

        
    }
};