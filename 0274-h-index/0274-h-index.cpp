class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int maxi=citations[citations.size()-1];
        for(int i=citations.size();i>0;i--){
                
            if(citations[citations.size()-i]>=i){
                return i;
            }

        }
        return 0;
        
    }
};