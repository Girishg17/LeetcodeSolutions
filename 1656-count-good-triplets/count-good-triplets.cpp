class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count=0;
        for(int i=0;i<arr.size()-2;i++){
            for(int j=i+1;j<arr.size()-1;j++){
                for(int k=j+1;k<arr.size();k++){
                    int first=abs(arr[i]-arr[j]);
                    int second=abs(arr[j] - arr[k]);
                    int third=abs(arr[i]-arr[k]);
                    if(first<=a && second<=b && third<=c)count++;
                }
            }
        }
        return count;
        
    }
};