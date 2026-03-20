class Solution {
public:
    string makeGood(string s) {
        std::stack<char> resStack;
        std::string result = "";
        for(int i = s.length() - 1;i >= 0;i --){
            if(!resStack.empty() && abs(s[i] - resStack.top()) == 32){
                resStack.pop();
            } else {
                resStack.push(s[i]);
            }
        }
        int l = resStack.size();
        for(int i = 0;i < l;i ++){
            result.push_back(resStack.top());
            resStack.pop();
        }
        return result;
    }
};