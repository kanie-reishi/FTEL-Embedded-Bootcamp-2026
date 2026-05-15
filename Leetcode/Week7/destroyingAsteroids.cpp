class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m = mass;
        int minVal = INT_MAX, maxVal = INT_MIN;

        for(int a : asteroids){
            minVal = min(minVal, a);
            maxVal = max(maxVal, a);
        }

        vector<int> count(maxVal + 1, 0);

        for (int a : asteroids) {
            if(a <= m){
                m += a;
            } else {
                count[a]++;
            }
        }
        for(int i = minVal;i <= maxVal; ++ i){
            if(count[i] > 0) {
                if(m >= i) {
                    m += 1LL * i * count[i];
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};