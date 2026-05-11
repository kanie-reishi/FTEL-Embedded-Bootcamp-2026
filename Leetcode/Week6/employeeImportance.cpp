/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> m;
        for(auto x: employees) m[x->id] = x;
        int sumImportance = 0;
        deque<Employee*> queue;
        queue.push_back(m[id]);
        while(!queue.empty()){
            auto p = queue.front();
            queue.pop_front();
            for(auto x:p -> subordinates) queue.push_back(m[x]);
            sumImportance += p->importance;
        }
        return sumImportance;
    }
};