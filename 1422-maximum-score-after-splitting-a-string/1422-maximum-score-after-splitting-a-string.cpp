class Solution {
public:
    int maxScore(string s) {
     vector<int>arr(s.size()+1,0);
     int co=0;
     for(int i=arr.size()-1;i>=0;i--){
         if(s[i]=='1')
            co++;
            arr[i]=co;
        }
        if(co==s.size()||co==0)return s.size()-1;
        int maxi=INT_MIN;
        int cz=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0')cz++;
            maxi=max(maxi,arr[i+1]+cz);
        }
        return maxi;

    }
};