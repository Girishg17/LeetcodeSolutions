class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dp(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}};
        dp[0][0]=0;
        q.push({0,{0,0}});
        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int wt=q.front().first;
            q.pop();
            for(auto &it:dir){
                int newrow=it[0]+row;
                int newcol=it[1]+col;

                if(newrow>=0&&newrow<heights.size()&&newcol>=0&&newcol<heights[0].size()){
                         int diff=max(wt,abs(heights[row][col]-heights[newrow][newcol]));

     

                        if(dp[newrow][newcol]>diff){
                            dp[newrow][newcol]=diff;
                            q.push({diff,{newrow,newcol}});
                        }

                }
            }
              
        }
        return dp[heights.size()-1][heights[0].size()-1];
        
    }
};