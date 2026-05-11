class Solution {
public:

    bool find(vector<vector<char>>& board, int i, int j, int idx, string &word, int m, int n){
        // Base case
        if(idx == word.size()) return true; // found

        // Edge cases
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '``'){
            return false;
        }

        if(board[i][j] != word[idx]) return false;

        // mark visited
        char temp = board[i][j];
        board[i][j] = '``';

        // main backtracking step 
        // checking 4 directions
        if(find(board, i+1, j, idx+1, word, m, n)) return true; //move up
        if(find(board, i-1, j, idx+1, word, m, n)) return true; //move down
        if(find(board, i, j+1, idx+1, word, m, n)) return true; //move right
        if(find(board, i, j-1, idx+1, word, m, n)) return true; //move left

        //update again for next iterations or checks
        board[i][j] = temp ;
        
        //if not found in upper loop then
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
       int m = board.size() ; //row size
       int n = board[0].size() ; //col size

        //Traverse the 2d matrix
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j] == word[0] && find(board,i,j,0,word,m,n)){
                    return true ; //found
                }

            }
        }

        return false ; //if not found in upper loop
    }
};