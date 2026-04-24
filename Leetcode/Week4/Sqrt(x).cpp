class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1){
            return x;
        }
        int x0 = x / 2;
        int x1 = floor((x0 + x / x0) / 2);
        while(x1 < x0){
            x0 = x1;
            x1 = floor((x0 + x / x0) / 2);
        }
        return x0;
    }
};