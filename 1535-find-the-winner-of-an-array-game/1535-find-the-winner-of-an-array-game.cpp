class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
       int winner=arr[0];
       int ct=0;
       for(int i=1;i<arr.size();i++){
           if(winner>arr[i]){
               ct++;
           }
           else{
               ct=1;
               winner=arr[i];
           }
           if(ct==k)return winner;
       }
       return winner;
    }
};