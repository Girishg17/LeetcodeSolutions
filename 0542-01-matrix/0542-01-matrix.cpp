class Solution
{
    public:

        vector<vector < int>> updateMatrix(vector<vector < int>> &mat)
        {
            vector<vector < int>> vis(mat.size(), vector<int> (mat[0].size(), 0));
            vector<vector < int>> dist(mat.size(), vector<int> (mat[0].size(), 0));
           
            int dir[][2] = {
		{ 0,
                    1 },
                { 1,
                    0 },
                { -1,
                    0 },
                { 0,
                    -1 }
            };
            queue<pair<int,pair<int, int>>> q;
            for (int i = 0; i < mat.size(); i++)
            {
                for (int j = 0; j < mat[0].size(); j++)
                {
                    if (mat[i][j] == 0)
                    {
                        q.push({0,{i,j}});
                        vis[i][j]=1;
                       	// ans[i][j]=dfs(mat,i,j);
                     
                }
            }
            }
            while(!q.empty()){
                pair<int,pair<int,int>>temp=q.front();
                q.pop();
                int step=temp.first;
                dist[temp.second.first][temp.second.second]=step;
                for(auto &it:dir){
                    int newrow=temp.second.first+it[0];
                    int newcol=temp.second.second+it[1];
                    if(newrow>=0&&newrow<mat.size()&&newcol<mat[0].size()&&newcol>=0&&vis[newrow][newcol]==0){
                        vis[newrow][newcol]=1;
                        q.push({step+1,{newrow,newcol}});
                    }
                }
            }

                return dist;
            
        }
        };