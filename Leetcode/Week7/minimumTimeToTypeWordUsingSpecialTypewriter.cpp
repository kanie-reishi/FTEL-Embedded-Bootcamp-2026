class Solution {
public:
    int minTimeToType(string word) {
        int ans =0;
        char curr = 'a';
        for (char& i : word){
            int diff = abs(i-curr);
            ans += min(diff, 26 - diff);
            ans ++;
            curr = i;
        }
        return ans;
    }
};