class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       int n=nums.size();
       vector<long>left(n);
       vector<long>right(n);
       int leftmax=nums[0];
       left[0]=0;
       for(int i=1;i<n;i++ ){
          left[i]=leftmax;
          leftmax=max(leftmax,nums[i]);
       }
       int rightmax=nums[n-1];
       right[n-1]=0;

       for(int j=n-2;j>=0;j--){
            right[j]=rightmax;
            rightmax=max(rightmax,nums[j]);
       }
        long ans=0;
       for(int i=0;i<n;i++){
        ans=max(ans,(left[i]-nums[i])*right[i]);
       }
       return ans;
    }
};