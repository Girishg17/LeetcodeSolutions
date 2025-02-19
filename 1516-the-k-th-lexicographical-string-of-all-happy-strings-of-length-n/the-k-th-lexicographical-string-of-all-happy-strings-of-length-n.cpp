class Solution {
public:
    void solve(int n,int k,string & ans,vector<string>&store,int i){
        if(i>n)return;
        if(i==n){
            
            store.push_back(ans);
            
            return;

        }
      vector<char>t={'a','b','c'};
      for(auto it:t){
        if(ans.empty() || ans.back() !=it){
        ans.push_back(it);
        solve(n,k,ans,store,i+1);
        ans.pop_back();
        }
      }

        
    }
    string getHappyString(int n, int k) {
        string ans="";
        vector<string>store;
        solve(n,k,ans,store,0);

        sort(store.begin(),store.end());
        if(store.size()<k)return "";
        return store[k-1];
    }
};