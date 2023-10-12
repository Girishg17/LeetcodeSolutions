class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low=0;
        long long high=sqrt(c)+1;
        while(low<=high){
            
            long res=low*low+ high*high;
            if(res==c)return true;
            if(res<c)low++;
            else if(res>c){
                high--;
            }
            
        }
        return false;
        
    }
};