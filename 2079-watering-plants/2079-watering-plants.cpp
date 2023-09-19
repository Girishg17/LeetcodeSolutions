class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {

        int i=0;
        int steps=0;
        int left=capacity;
        while(i<plants.size()){

            while(i<plants.size()&&plants[i]<=left){
                left=left-plants[i];
                i++;
                
                steps++;
            }
            if(i==plants.size())return steps;
           
            
                steps=steps+i*2;
                left=capacity;
            
            
            
        }
        return steps;
        
    }
};