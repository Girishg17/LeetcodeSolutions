class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>>st;
        st.insert({0,0});
        int x=0,y=0;
        for(int i=0;i<path.size();i++){
            if(path[i]=='N'){
                y=y+1;
            }
            else if(path[i]=='E'){
                x=x+1;
            }
            else if(path[i]=='S'){
                y=y-1;
            }
            else if(path[i]=='W'){
                x=x-1;
            }
            if(st.count({x,y}))return true;
            st.insert({x,y});
        }
        return false;
        
    }
};