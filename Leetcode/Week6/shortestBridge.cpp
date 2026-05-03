class Solution {
public:
    pair<int, int> findFirstIsland(vector<vector<int>>& grid){
        for(int i  = 0; i < grid.size();i ++){
            for(int j = 0;j < grid[i].size();j ++){
                if(grid[i][j] == 1){
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<int> dir={-1, 0, 1, 0, -1};
        int n = grid.size();
        int bridge = 0;

        stack<pair<int, int>> s;
        queue<pair<int, int>> q;

        s.push(findFirstIsland(grid));
        while(!s.empty()){
            pair<int, int> p = s.top();
            s.pop();
            q.push({p.first, p.second});
            grid[p.first][p.second] = 2;
            for(int i = 0;i < 4;i ++){
                int r = p.first + dir[i];
                int c = p.second + dir[i + 1];
                if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 1){
                    grid[r][c] = 2;
                    s.push({r, c});
                }
            }
        }
        while(!q.empty()){
            int sz = q.size();
            while(sz --){
                pair<int, int> p = q.front();
                q.pop();
                for(int i = 0;i < 4;i ++){
                    int r = p.first + dir[i];
                    int c = p.second + dir[i + 1];
                    if(r >= 0 && r < n && c >= 0 && c < n){
                        if(grid[r][c] == 0){
                            q.push({r, c});
                            grid[r][c] = 2;
                        } else if(grid[r][c] == 1){
                            return bridge;
                        }
                    }
                }
            }
            bridge ++;
        }
        return bridge;
    }
};