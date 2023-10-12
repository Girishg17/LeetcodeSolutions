/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        int low=0;
        int n=m.length();
        int high=m.length()-1;
        int index;
        while(low<=high){
            int mid=(low+high)/2;
int prev = (mid - 1 >= 0) ? m.get(mid - 1) : INT_MIN;
int curr = m.get(mid);
int post = (mid + 1 < n) ? m.get(mid + 1) : INT_MIN;
            if(prev<curr && curr>post){
                index=mid;
                break;
            }
            if(post>curr){
                
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(index==-1)return -1;
        int low1=0;
        int high1=index-1;
        int low2=index;
        int high2=n-1;
        while(low1<=high1){
            int mid1=(low1+high1)/2;
            int value=m.get(mid1);
            if(value==target){
                return mid1;

            }
            if(value>target){
                high1=mid1-1;
            }
            else{
                low1=mid1+1;
            }


        }

          while(low2<=high2){
            int mid2=(low2+high2)/2;
            int value=m.get(mid2);
            if(value==target){
                return mid2;

            }
            if(value>target){
                low2=mid2+1;
                
            }
            else{
                high2=mid2-1;
            }


        }
        return -1;
        
    }
};