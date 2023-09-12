class Solution {
public:
    int minDeletions(string s) {
       vector<int>mp(26,0);
       for(auto &it:s){
           mp[it-'a']++;
       }
       sort(mp.begin(),mp.end());
       int delt=0;
       for(int i=24;i>=0;i--){
           if(mp[i]==0)break;
           if(mp[i]>=mp[i+1]){
               int prev=mp[i];
               mp[i]=max(mp[i+1]-1,0);
               delt+=prev-mp[i];
           }
       }
       return delt;
        
    }
};