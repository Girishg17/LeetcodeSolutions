class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=1e5;i++){
            int x=i;
            int y=0;
            while(x>0){
                y=y*10+(x%10);
                x/=10;
            }
            if(i+y==num)return true;

        }
        return false;
        
    }
};