class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
       int refill=0;
       int i=0;
       int j=plants.size()-1;
       int capa=capacityA;
       int capb=capacityB;
       while(i<=j){
           if(i==j){
              if(capacityA<plants[i] && capacityB< plants[j])refill++;
              break;
           }
           if(capacityA<plants[i]){
               refill++;
               capacityA= capa;
           }
           if(capacityB<plants[j]){
               refill++;
               capacityB= capb;
           }
           capacityA-=plants[i];
           capacityB-=plants[j];
           i++;
           j--;
       }
        return refill;
        
    }
};