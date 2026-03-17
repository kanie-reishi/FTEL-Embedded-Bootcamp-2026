/*
 * Problem: 657. Robot Return to Origin
 * Link: https://leetcode.com/problems/robot-return-to-origin/
 * Difficulty: Easy
 * 
 * Description:
 * There is a robot starting at the position (0, 0), the origin, on a 2D plane.
 * Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
 * 
 * Time Complexity: O(N) where N is the number of moves. We iterate through the string once.
 * Space Complexity: O(1) since we only use two variables for the position.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int posX = 0, posY = 0;
        for(int i = 0; i < moves.length(); i++){
            switch(moves[i]){
                case 'U': posY += 1; break;
                case 'D': posY -= 1; break;
                case 'R': posX += 1; break;
                case 'L': posX -= 1; break;
                default: break;
            }
        }
        return (posX == 0) && (posY == 0);
    }
};

// Local Testing
int main() {
    Solution solution;
    
    // Test Case 1
    string moves1 = "UD";
    cout << "Input: " << moves1 << "\nOutput: " 
         << (solution.judgeCircle(moves1) ? "true" : "false") 
         << " (Expected: true)\n\n";

    // Test Case 2
    string moves2 = "LL";
    cout << "Input: " << moves2 << "\nOutput: " 
         << (solution.judgeCircle(moves2) ? "true" : "false") 
         << " (Expected: false)\n\n";

    return 0;
}
