class Solution {
public:
    int minimumPushes(string word) {
        map<int,int>mp;
        for(auto it:word){
            mp[it]++;
        }
        vector<int>temp;
        for(auto it:mp){
           
            temp.push_back(it.second);
        }
        sort(temp.begin(),temp.end(),greater<int>());
        int push=1;
        int mini=0;
        for(int i=0;i<temp.size();i++){
            
            cout<<push<<",";
            mini=mini+push*temp[i];
            if(((i+1)%8) ==0){
                push++;
            }
        }
        return mini;

    }
};