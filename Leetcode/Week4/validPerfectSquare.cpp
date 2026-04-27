class Solution {
public:
    bool isPerfectSquare(int num) {
        long r = num / 2;
        if(num <= 1){
            return true;
        }
        while (r*r > num){
            r = floor((r + num / r) / 2);
        }
        return r*r == num;
    }
};