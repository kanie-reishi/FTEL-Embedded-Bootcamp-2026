class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vp;

        for(int i = 0; i < speed.size(); i ++){
            vp.push_back({position[i], speed[i]});
        }

        sort(vp.begin(), vp.end());

        int ans = 0;
        stack<float> st;

        for(auto& it : vp) {
            float temp = (target - it.first);
            temp /= it.second;

            while(!st.empty() && st.top() <= temp)
                st.pop();
            st.push(temp);
        }
        return st.size();
    }
};