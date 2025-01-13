class Solution {
public:
    int minimumLength(string s) {
        unordered_map<int,int>mp;
        int count=0;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it: mp){
            int x=it.second;
            if(x%2==1){
                count=count+ x-1;
            }
            else{
                count=count+x-2;
            }
        }
        return s.size()-count;
    }
};