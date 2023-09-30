class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l=matrix[0][0];
        int h=matrix[matrix.size()-1][matrix.size()-1];
       
        while(l<=h){
             int count=0;
            int mid=l+(h-l)/2;
            for(int i=0;i<matrix.size();i++){
                count+=upper_bound(matrix[i].begin() , matrix[i].end(),mid) - matrix[i].begin();
            }
            if(count<k){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return l;
        
    }
};