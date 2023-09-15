class Solution {
public:
    int numTrees(int n) {
        if(n==0)return 1;
        if(n==1)return 1;
        int total=0;
        for(int i=0;i<n;i++){
            total=total+numTrees(i)*numTrees(n-1-i);


        }
        return total;
    }
};