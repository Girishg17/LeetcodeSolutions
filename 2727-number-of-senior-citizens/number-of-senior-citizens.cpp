class Solution {
public:
    int countSeniors(vector<string>& details) {
        int total=0;
        for(int i=0;i<details.size();i++){
            string temp=details[i].substr(11,2);
            if(stoi(temp)>60)total++;
        }
        return total;
    }
};