class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int i = 0; i < arr.size();i ++){
            map[arr[i]] = map[arr[i]] + 1;
        }
        for(int i = 0;i < arr.size();i ++){
            if(arr[i] == 0 && map[arr[i]] > 1){
                return true;
            }
            if(map[arr[i]*2] && arr[i] != 0){
                return true;
            }
        }
        return false;
    }
};