class Solution {
public:
   long long MOD = 1e9 + 7;

    long long cnt(int length,int zero, int one, vector<long long>&dp) {
        if(length==0)return 1;
        if(length<0)return 0;
        if(dp[length]!=-1)return dp[length];
        int ans=0;
        if(length>=zero){
            ans+=cnt(length-zero,zero,one,dp);

        }
        if(length>=one){
 ans+=cnt(length-one,zero,one,dp);
        }
        return dp[length]=ans%MOD;

      
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        long long  ans=0;
      vector<long long>dp(low+high+1,-1);
       for(int i=low;i<=high;i++){
           ans+=cnt(i,zero,one,dp)%MOD;

       }
       return ans%MOD;
    }
};
