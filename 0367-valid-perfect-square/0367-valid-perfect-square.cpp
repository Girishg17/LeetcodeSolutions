class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)return true;

        
     int high=num/2;
     int low=0;
     while(low<=high){
         long long mid=(low+high)/2;
         if(mid*mid==num)return true;
         else if(mid*mid >num){
             high=mid-1;
         }
         else{
             low=mid+1;
         }
     }
     return false;
    }
};