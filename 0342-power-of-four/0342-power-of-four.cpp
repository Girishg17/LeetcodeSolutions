class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0)return false;
       
       if((n & (n-1))==0 && n & 0x55555555){
           return true;
       }
       return false;
        
    }
};