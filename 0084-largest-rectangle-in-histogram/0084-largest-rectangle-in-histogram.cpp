class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>leftsmall(n);
        vector<int>rightsmall(n);
        leftsmall[0]=0;
        stack<int>st;
        st.push(0);
        for(int i=1;i<heights.size();i++){
        while(!st.empty() && heights[st.top()]>= heights[i])st.pop();
        if(st.empty())leftsmall[i]=0;
        else{
            leftsmall[i]=st.top()+1;
        }
        st.push(i);
        }
        st={};
        rightsmall[n-1]=n-1;

          for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()]>= heights[i])st.pop();
        if(st.empty())rightsmall[i]=n-1;
        else{
            rightsmall[i]=st.top()-1;
        }
        st.push(i);
        }
        for(int i=0;i<leftsmall.size();i++){
            cout<<rightsmall[i]<<endl;
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,heights[i]*(rightsmall[i]-leftsmall[i]+1));
        }
        return maxi;
        
    }
};