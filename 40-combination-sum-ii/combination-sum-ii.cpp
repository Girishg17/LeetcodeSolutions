class Solution {
public:
   void solve(vector<int>&candi,int target,vector<vector<int>>&ans,int i,vector<int>&temp,int sum){
    if(sum==target){
        ans.push_back(temp);
        return;
    }
    if(i>=candi.size() || sum>target){return;}
   for(int j=i;j<candi.size();j++){
    if(j>i && candi[j-1]==candi[j])continue;
    temp.push_back(candi[j]);
    solve(candi,target,ans,j+1,temp,sum+candi[j]);
    temp.pop_back();

   }
    
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,ans,0,temp,0);
        return ans;
    }
};