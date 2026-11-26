class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()) {
            return "";
        }

        unordered_map<char, int> mp1;

        for (char c : t) {
            mp1[c]++;
        }

        unordered_map<char, int> mp2;

        int required = mp1.size();
        int formed = 0;

        int l = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int r = 0; r < s.size(); r++) {

            char c = s[r];

            if (mp1.find(c) != mp1.end()) {

                mp2[c]++;

                if (mp2[c] == mp1[c]) {
                    formed++;
                }
            }

            while (formed == required) {

                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];

                if (mp1.find(leftChar) != mp1.end()) {

                    if (mp2[leftChar] == mp1[leftChar]) {
                        formed--;
                    }

                    mp2[leftChar]--;
                }

                l++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};
