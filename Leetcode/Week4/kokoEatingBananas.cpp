class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0;
        for(int i = 0;i < piles.size();i ++){
            if(piles[i] > max){
                max = piles[i];
            }
        }
        int left = 1;
        int right = max;
        int mid;
        int accum; //Total hours
        while(left < right){
            mid = left + (right - left) / 2;
            cout << mid << " " << left << " " << right << " ";
            accum = 0;
            for(int i = 0;i < piles.size();i ++){
                accum += (piles[i] + mid - 1) / mid;
            }
            cout << accum << "\n";
            if(accum <= h){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};