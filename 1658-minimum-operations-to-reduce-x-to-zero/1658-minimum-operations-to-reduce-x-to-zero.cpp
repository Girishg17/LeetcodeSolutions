class Solution {
public:
    
    int minOperations(vector<int>& nums, int x) {
        vector<int>prefixL(nums.begin(),nums.end());
        vector<int>prefixR(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            prefixL[i]=prefixL[i-1]+prefixL[i];
        }
        for(int i=nums.size()-2;i>=0;i--){
            prefixR[i]=prefixR[i+1]+prefixR[i];
        }
        reverse(prefixR.begin(),prefixR.end());
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(prefixL[i]>x)break;
            if(prefixL[i]==x)ans=min(ans,i+1);
            else{
                if(binary_search(prefixR.begin(),prefixR.end()-(i+1),x-prefixL[i])){
                    int lb=lower_bound(prefixR.begin(),prefixR.end()-(i+1),x-prefixL[i])-prefixR.begin();
                    ans=min(ans,i+lb+2);
                }

            }
        }

         for(int i=0;i<nums.size();i++){
            if(prefixR[i]>x)break;
            if(prefixR[i]==x)ans=min(ans,i+1);
            else{
                if(binary_search(prefixL.begin(),prefixL.end()-(i+1),x-prefixR[i])){
                    int lb=lower_bound(prefixL.begin(),prefixL.end()-(i+1),x-prefixR[i])-prefixL.begin();
                    ans=min(ans,i+lb+2);
                }

            }
            
        }
if(ans==INT_MAX)return -1;
    return ans;
   
    }
};