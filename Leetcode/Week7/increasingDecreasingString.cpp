class Solution {
public:
    string ans;
    void charErase(map<char, int> &mp, char ch){
        if(mp.find(ch) != mp.end()){
            ans += ch;
            mp[ch] --;
            if(not mp[ch]) mp.erase(ch);
        }
    }
    string sortString(string s) {
        map<char, int> mp;
        for(char ch:s) mp[ch]++;
        
        while(mp.size())
        {
            for(char ch='a'; ch <= 'z'; ch++)
                charErase(mp, ch);
            for(char ch='z'; ch >= 'a'; ch--)
                charErase(mp, ch);
        }
        return ans;
    }
};