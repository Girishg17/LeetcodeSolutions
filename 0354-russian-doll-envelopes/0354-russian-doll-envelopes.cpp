class Solution {
public:
    // int recursion(int i,vector<vector<int>>& nums,int prev, vector<vector<int>>&dp){
    //     if(i>=nums.size())return 0;
    //     if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    //     int take=0;
    //     if(prev==-1||nums[i][1]>nums[prev][1]){
    //         take=1+recursion(i+1,nums,i,dp);
    //     }
    //     int notake=recursion(i+1,nums,prev,dp);
    //     return dp[i][prev+1]=max(take,notake);
        
    // }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0)
            return 0;
        
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0]&&a[1] > b[1]);
        });

        // vector<vector<int>>dp(envelopes.size(),vector<int>(envelopes.size()+1,-1));
        // return recursion(0,envelopes,-1,dp);

        //optimal
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            if(envelopes[i][1]>ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[index]=envelopes[i][1];
            }
        }
        return ans.size();
        
        
    }
};
