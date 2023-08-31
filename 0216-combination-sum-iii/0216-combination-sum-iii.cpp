class Solution {
public:
    void solve(int k,int n,vector<vector<int>>&ans,int i,int sum,vector<int>&temp,int c){
        
        if(sum>n)return;
        if(sum==n&&k==c){
            ans.push_back(temp);
            return;
        }
        if(i>=10)return;
        if(sum+i<=n){
            temp.push_back(i);
            solve(k,n,ans,i+1,sum+i,temp,c+1);
          
            temp.pop_back();
        }
        solve(k,n,ans,i+1,sum,temp,c);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(k,n,ans,1,0,temp,0);
        return ans;
        
    }
};