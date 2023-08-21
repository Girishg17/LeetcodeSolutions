class Solution {
public:
    bool ispossible(vector<int>& dist,int mid,double hour){
        double ans=0;
        for(int i=0;i<dist.size();i++){
            double d=dist[i]*1.0/mid;
            if(i!=dist.size()-1){
                ans+=ceil(d);
            }
            else{
                ans+=d;
            }
            if(ans>hour)return false;
        }
        if(ans<=hour)return true;
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
     
        int l=1;
        int r=1e7;
       int minspeed=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
           
          
            if(ispossible(dist,mid,hour)){
                minspeed=mid;
                r=mid-1;

            }
            else{
                l=mid+1;
            }
            
        }
       
        return minspeed;
    }
};