class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> dir = {-1, 0, 1, 0, -1};
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;
        int step = 0;
        q.push({entrance[0], entrance[1]});
        while(!q.empty()){
            int sz = q.size();
            while(sz --){
                pair<int, int>  p = q.front();
                q.pop();
                for(int i = 0;i < 4;i ++){
                    int r = p.first + dir[i];
                    int c = p.second + dir[i + 1];
                    if(r >= 0 && r < m && c >= 0 && c < n && maze[r][c] == '.'){
                        if((r == 0 || c == 0 || r == m - 1 || c == n - 1) && !(r == entrance[0] && c == entrance[1])){
                            return step + 1;
                        }
                        q.push({r, c});
                        maze[r][c] = '+';
                    }
                }
            }
            step ++;
        }
        return -1;
    }
};