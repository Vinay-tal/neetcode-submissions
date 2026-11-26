class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return 0;
        }
        unordered_map<char,int> s1;
        for(char x : s){
            s1[x]++;
        }
        unordered_map<char,int> s2;
        for(char x : t){
            s2[x]++;
        }
        for(char x : s){
        if(s1[x]!=s2[x]){
            return 0;
        }
        }
        return 1;
    }
};
