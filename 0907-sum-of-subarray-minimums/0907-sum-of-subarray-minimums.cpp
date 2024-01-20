class Solution {
public:
    
    int sumSubarrayMins(vector<int>& arr) {
        
      vector<int>ans(arr.size());
      stack<pair<int,int>>st;
      
      for(int i=0;i<arr.size();i++){
          while(!st.empty() && st.top().first>arr[i]){
              st.pop();
          }
          if(st.empty())ans[i]=arr[i]*(i+1);
          else{
              ans[i]=ans[st.top().second]+arr[i]*(i-st.top().second);
          }
          st.push({arr[i],i});
      }
      int result=0;
      for(int i=0;i<ans.size();i++){
           result = (result + ans[i]) % 1000000007;
      }
     
      return result;
        
    }
};