class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans(2);
        map<int,vector<int>>mp;
        for(auto it:matches){
            mp[it[1]].push_back(it[0]);
        }
        vector<int>winner;
        set<int>st;
        for(int i=0;i<matches.size();i++){
           if(mp.find(matches[i][0])==mp.end()&&!st.count(matches[i][0])){
               
               winner.push_back(matches[i][0]); 
               st.insert(matches[i][0]);
           }
        }
        vector<int>looser;
        for(auto it:mp){
            if(it.second.size()==1)looser.push_back(it.first);
        }
        sort(winner.begin(),winner.end());
        sort(looser.begin(),looser.end());
        ans[0]=winner;
        ans[1]=looser;
        return ans;
    }
};