class Solution {
public:
vector<vector<int>>finalans;
  void solve(int num,int n,int k,vector<int>&ans){
    
    
     if(num==n+1){ 
         if(ans.size()==k){
          finalans.push_back(ans);
          

      }
      return;
  }
   

    ans.push_back(num);
    solve(num+1,n,k,ans);
    ans.pop_back();
    solve(num+1,n,k,ans);



  }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
      solve(1,n,k,ans);
      return finalans;
      
        
    }
};