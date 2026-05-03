class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        
        for(int i = 0;i < n;i ++){
            if (visited[i]) continue;  

            provinces ++;
            stack<int> s;
            s.push(i);
            
            while(!s.empty()){
                int curr = s.top();
                s.pop();
                if(visited[curr]) continue;
                visited[curr] = true;
                for(int j = 0;j < n;j ++){
                    if(isConnected[curr][j] == 1 && !visited[j]){
                        s.push(j);
                    }
                }
            }
        }
        return provinces;
    }
};