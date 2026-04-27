class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        vector<int> row{1, 0, 0, -1};
        vector<int> col{0, -1, 1, 0};
        queue<pair<int, int>> q;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    ans ++;
                    q.push({i, j});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        vis[x][y] = 1;
                        for(int k = 0;k < 4;k ++){
                            int r = x + row[k];
                            int c = y + col[k];
                            if(r >= 0 && r < n && c >= 0 && c < m && vis[r][c] == 0 && grid[r][c] == '1'){
                                q.push({r, c});
                                vis[r][c] = 1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};