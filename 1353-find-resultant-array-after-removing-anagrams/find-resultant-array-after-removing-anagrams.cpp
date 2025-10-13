class Solution {
public:
    bool compare(string one,string two){
        if(one.size() != two.size())return false;
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        return one==two;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        unordered_map<char,int>mp;
        int j=0;
        ans.push_back(words[0]);
        for(int i=0;i<words.size();i++){
            if(compare(words[j],words[i])){
                continue;
            }
            ans.push_back(words[i]);
            j=i;
        }
        return ans;
    }
};