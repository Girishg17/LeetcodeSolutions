class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.size()<=2)return false;
        int count_a=0;
        int count_b=0;
        int count;
        int i=0;
        int j=0;
        while(i<colors.size()){
             count=0;
            while(j<colors.size() &&colors[j]=='A'){
                count++;
                j++;
            }
            if(count>=3){
                count_a=count_a+count-3+1;
            }
            i=j+1;
            j=i;
        }

        i=0;
        j=0;
        while(i<colors.size()){
            count=0;
            while(j<colors.size() &&colors[j]=='B'){
                count++;
                j++;
            }
            if(count>=3){
                count_b=count_b+count-3+1;
            }
            i=j+1;
            j=i;
        }
        // cout<<count_a<<endl;
        // cout<<count_b<<endl;

        if(count_a>count_b)return true;
        
        return false;
        

        
    }
};