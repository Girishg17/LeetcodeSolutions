class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>temp;
        for(auto &it:timePoints){
            int hour=stoi(it.substr(0,2));
            int hour_in_min=hour*60;
            int minute=stoi(it.substr(3,5));
            cout<<minute<<endl;
            int total=hour_in_min+minute;

            temp.push_back(total);

        }
        int ans=INT_MAX;
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size()-1;i++){
            int diff=temp[i+1]-temp[i];
            ans=min(ans,diff);
        }
        return min(ans,24*60-temp[temp.size()-1]+temp[0]);
        
    }
};