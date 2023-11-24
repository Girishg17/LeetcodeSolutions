class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int start=0;
        int end=piles.size()-1;
        int ans=0;
        while(start<end){
            start++;
            end--;
            ans+=piles[end];
            end--;
        }
        return ans;
        
    }
};


