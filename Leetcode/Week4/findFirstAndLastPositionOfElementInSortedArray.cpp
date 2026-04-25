class Solution {
public:
    int search(int target, vector<int>& nums){
        int l = 0;
        int h = nums.size() - 1;
        int mid;
        while(l <= h){
            mid = (l + h) >> 1;
            if(nums[mid] < target){
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> output;
        if(nums.empty()){
            output.push_back(-1);
            output.push_back(-1);
            return output;
        }
        int l0 = search(target, nums);
        int l1 = search(target + 1, nums) - 1;
        if(l0 < nums.size() && nums[l0] == target){
            return {l0, l1};
        }
        return {-1, -1};
    }
};