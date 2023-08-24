class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map<int,vector<char>>mp;
        // for(int i=0;i<strs.size();i++){
        //     for(int j=0;j<strs[i].size();j++){
                
        //         mp[i].push_back(strs[i][j]);
        //     }
        //     sort(mp[i].begin(),mp[i].end());

        // }
        // vector<vector<string>>ans;
        // vector<int>vis(strs.size(),0);
        // for(int i=0;i<mp.size();i++){
        //     if(vis[i]==0){
        //   vector<string>temp;
        //   temp.push_back(strs[i]);
        //   vis[i]=1;
        //     for(int j=i+1;j<mp.size();j++){
        //         if(mp[i]==mp[j]&&vis[j]==0){
        //             vis[j]=1;
        //             temp.push_back(strs[j]);
        //             // mp.erase(j);
                                        
        //         }
        //     }
        //     ans.push_back(temp);
        //     temp.clear();
        //     }
        // }
        // for(int i=0;i<mp[0].size();i++){
        //     cout<<mp[0][i];
        // }

        map<string,vector<int>>mp;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(i);
            
               
                }


        for(auto &it:mp){
            vector<string>temp;
            for(int i=0;i<it.second.size();i++){
                temp.push_back(strs[it.second[i]]);
            }
            ans.push_back(temp);
            temp.clear();
            
        }
        return ans;
        }
        
    
};