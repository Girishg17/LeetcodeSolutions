class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        int total=0;
        vector<int>g(n,0);
        for(int i=0;i<garbage.size();i++){
            for(int j=0;j<garbage[i].size();j++){
                if(garbage[i][j]=='G')g[i]++;
            }
        }
       
        int start=n-1;
        while(start>=0 && g[start]==0){
            start--;
        }
        
        for(int j=start;j>=0;j--){
            if(j!=0)
            total+=g[j]+travel[j-1];
            else{
                total+=g[j];
            }
        }


     vector<int>p(n,0);
        for(int i=0;i<garbage.size();i++){
            for(int j=0;j<garbage[i].size();j++){
                if(garbage[i][j]=='P')p[i]++;
            }
        }
       
         start=n-1;
        while(start>=0 && p[start]==0){
            start--;
        }
        
        for(int j=start;j>=0;j--){
            if(j!=0)
            total+=p[j]+travel[j-1];
            else{
                total+=p[j];
            }
        }

         vector<int>m(n,0);
        for(int i=0;i<garbage.size();i++){
            for(int j=0;j<garbage[i].size();j++){
                if(garbage[i][j]=='M')m[i]++;
            }
        }
       
         start=n-1;
        while(start>=0 && m[start]==0){
            start--;
        }
        
        for(int j=start;j>=0;j--){
            if(j!=0)
            total+=m[j]+travel[j-1];
            else{
                total+=m[j];
            }
        }

        return total;




    }
};