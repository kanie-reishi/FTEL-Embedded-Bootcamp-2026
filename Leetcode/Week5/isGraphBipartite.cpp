class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        vector<int> color(graph.size(), - 1);
        for(int i = 0;i < graph.size();i ++){
            if(color[i] == -1){
                q.push(i);
                color[i] = 0;
            }
            while(!q.empty()){
                int currentColor = color[q.front()];
                int currentNode = q.front();
                q.pop();
                for(int j = 0;j < graph[currentNode].size();j ++){
                    if(color[graph[currentNode][j]] == -1){
                        q.push(graph[currentNode][j]);
                        color[graph[currentNode][j]] = 1 - currentColor;
                    } else if(color[graph[currentNode][j]] == currentColor){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};