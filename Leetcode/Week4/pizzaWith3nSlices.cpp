class Solution {
public:
    int solve(vector<int>& slices){
        int n = slices.size();
        int k = (n + 3 - 1) / 3;

        vector<int> prev2(k + 1, 0), prev1(k + 1, 0), cur(k + 1, 0);

        // base case
        prev2[0] = 0;
        prev2[1] = slices[0];

        prev1[0] = 0;
        prev1[1] = max(slices[0], slices[1]);

        for(int i = 2; i < n; i++){
            cur[0] = 0;
            for(int j = 1; j <= k; j++){
                cur[j] = max(
                    prev1[j],
                    prev2[j-1] + slices[i]
                );
            }
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1[k];
    }

    int maxSizeSlices(vector<int>& slices) {
        vector<int> case1(slices.begin(), slices.end() - 1);
        vector<int> case2(slices.begin() + 1, slices.end());
        return max(solve(case1), solve(case2));
    }
};