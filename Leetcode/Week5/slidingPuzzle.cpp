class Solution {
public:
    int findZeroPos(string arrString){
        for(int i = 0;i < arrString.size();i ++){
            if(arrString[i] == '0'){
                return i;
            }
        }
        return -1;
    }
    string boardToString(vector<vector<int>>& board){
        string output = "";
        for(int i = 0;i < board.size();i ++){
            for(int j = 0;j < board[i].size();j ++){
                output += to_string(board[i][j]);
            }
        }
        return output;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> visited;
        vector<vector<int>> neighbors = {
            {1,3},    // index 0
            {0,2,4},  // 1
            {1,5},    // 2
            {0,4},    // 3
            {1,3,5},  // 4
            {2,4}     // 5
        };
        queue<pair<string, int>> q;
        string ans = "123450";
        int move = 0;

        string firstState = boardToString(board);
        int zeroPos = findZeroPos(firstState);
        q.push({firstState, zeroPos});
        visited.insert(firstState);

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto [curState, zeroPos] = q.front(); q.pop();

                if(curState == ans) return move;

                for(int next : neighbors[zeroPos]){
                    string nextState = curState;
                    swap(nextState[zeroPos], nextState[next]);

                    if(visited.count(nextState)) continue;

                    visited.insert(nextState);
                    q.push({nextState, next});
                }
            }
            move++;
        }
        return -1;
    }
};