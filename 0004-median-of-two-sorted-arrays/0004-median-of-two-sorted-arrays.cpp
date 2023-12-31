class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size();
        int size2=nums2.size();
        if(size1>size2)return findMedianSortedArrays(nums2,nums1);
        int low=0;
        int high=size1;
        int total=(size1+size2+1)/2;
        int n=size1+size2;
       
        while(low<=high){
            int mid1=(high+low)>>1;
            int mid2=total-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1-1>=0)l1=nums1[mid1-1];
            if(mid2-1>=0)l2=nums2[mid2-1];
            if(mid1<size1)r1=nums1[mid1];
            if(mid2<size2)r2=nums2[mid2];
            if(l2<=r1&&l1<=r2){
                cout<<l1<<","<<l2<<","<<r1<<","<<r2<<",";
                if(n%2==1)return max(l1,l2);
                else{
                    return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
                }
            }
            else if(l1>r2){
                high=mid1-1;

            }
            else{
                low=mid1+1;
            }
        }
        return 0;


    
        
        
    }
};