class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        if(x==1)return 1;
        long long end=x/2;
        long long start=1;
        long long prod=0;
        long long mid;
        while(start<=end ){
            mid=start+(end-start)/2;
            prod=mid*mid;
            if(prod<=x && ((mid+1)*(mid+1))>x)return mid;
            if(prod>x){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return -1;

    }
};