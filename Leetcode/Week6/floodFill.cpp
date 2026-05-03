class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<int> dir={-1, 0, 1, 0, -1};
        int m = image.size();
        int n = image[0].size();
        int originColor = image[sr][sc];
        if(color == originColor){
            return image;
        }
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            for(int i = 0;i < 4;i ++){
                int r = p.first + dir[i];
                int c = p.second + dir[i + 1];
                if(r >= 0 && r < m && c >= 0 && c < n && image[r][c] == originColor){
                    image[r][c] = color;
                    q.push({r, c});
                }
            }
        }
        return image;
    }
};