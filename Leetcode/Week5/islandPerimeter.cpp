class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int stripes = 0;
        for(int i = 0;i < grid.size();i ++){
            for(int j = 0;j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    if(i == 0){
                        stripes += 1;
                    } else if(grid[i - 1][j] != 1){
                        stripes += 1;
                    }
                    if(i == grid.size() - 1){
                        stripes += 1;
                    } else if(grid[i + 1][j] != 1){
                        stripes += 1;
                    }
                    if(j == 0){
                        stripes += 1;
                    } else if(grid[i][j - 1] != 1){
                        stripes += 1;
                    }
                    if(j == grid[i].size() - 1){
                        stripes += 1;
                    } else if(grid[i][j + 1] != 1){
                        stripes += 1;
                    }
                }
            }
        }
        return stripes;
    }
};