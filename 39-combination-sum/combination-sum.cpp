class Solution {
public:
    void solve(vector<int>& candidates, int i, int target,int sum,vector<vector<int>>&ans,vector<int>&temp){
        if(sum>target)return;
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(i>=candidates.size())return;


            temp.push_back(candidates[i]);
            solve(candidates,i,target,sum+candidates[i],ans,temp);
            temp.pop_back();
            solve(candidates,i+1,target,sum,ans,temp);
            
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(candidates,0,target,0,ans,temp);
        return ans;
    }
};