class Solution {
public:
    int mySqrt(int x) {
           if(x==0)return 0;
        if(x==1)return 1;
        long long int high=x/2;
        long long int start=1;
        while(start<=high){
            long long int mid=start+(high-start)/2;
            if(mid*mid<=x &&(mid+1)*(mid+1)>x)return mid;
            if(mid*mid>x){
                high=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return -1;
        
    }
};