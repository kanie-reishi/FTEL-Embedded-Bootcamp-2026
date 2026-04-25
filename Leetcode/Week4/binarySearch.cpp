class Solution {
public:
    int search(vector<int>& nums, int target) {
        int median = nums.size() / 2;
        int high = nums.size();
        int low = 0;
        while(nums[median] != target){
            if(target > nums[median]){
                low = median;
                median = (median + high) / 2;
            }else{
                high = median;
                median = (median + low) / 2;
            }
            if((high == low ||high == low + 1) && nums[median] != target){
                return - 1;
            }
        }
        return median;
    }
};