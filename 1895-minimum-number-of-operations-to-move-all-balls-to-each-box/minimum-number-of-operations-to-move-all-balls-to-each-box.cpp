class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int j=0;
            int temp=0;
            while(j<n){
                if(boxes[j]=='1'){
                    temp+=abs(j-i);
                }
                j++;
            }
            ans[i]=temp;

        }
        return ans;
        
    }
};