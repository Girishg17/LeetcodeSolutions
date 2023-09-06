class Solution {
public:
    set<vector<int>>s;
    void solve(vector<int>&nums,int i,vector<int>&res,vector<vector<int>>&ans,vector<int>&vis){
        if(res.size()==nums.size()){
            if(s.find(res)==s.end()){
               ans.push_back(res);
              
             s.insert(res);
            }
            return;
        }
        for(int j=0;j<nums.size();j++){
            
            if(vis[j]==0 ){
                res.push_back(nums[j]);
                vis[j]=1;
                solve(nums,i,res,ans,vis);
                res.pop_back();
                vis[j]=0;
            }

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>result;
        vector<vector<int>>ans;
        vector<int>vis(nums.size(),0);
        sort(nums.begin(),nums.end());
        
            solve(nums,0,result,ans,vis);
        
    
        return ans;
        
    }
};