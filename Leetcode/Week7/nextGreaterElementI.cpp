class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        stack<int> s;
        for(int i = 0;i < nums2.size();i ++){
            while(!s.empty() && s.top() < nums2[i]){
                int x = s.top();
                s.pop();
                map[x] = nums2[i];
            }
            s.push(nums2[i]);
        }
        for(int i = 0;i < nums1.size();i ++){
            if(map.find(nums1[i]) != map.end()){
                nums1[i] = map[nums1[i]];
            } else {
                nums1[i] = -1;
            }
        }
        return nums1;
    }
};