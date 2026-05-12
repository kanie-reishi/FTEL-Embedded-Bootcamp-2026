class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int k = q.front();
            q.pop();

            for (int key : rooms[k]) {
                if (!visited[key]) {
                    visited[key] = true;
                    q.push(key);
                }
            }
        }

        for (bool v : visited) {
            if (!v) return false;
        }

        return true;
    }
};