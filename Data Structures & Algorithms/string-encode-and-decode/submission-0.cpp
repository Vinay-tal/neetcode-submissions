class Solution {
public:

    string encode(vector<string>& strs) {
        string store;

        for (string& s : strs) {
            store += to_string(s.size());
            store.push_back('#');
            store += s;
        }

        return store;
    }

    vector<string> decode(string store) {
        vector<string> decoded;

        int i = 0;

        while (i < store.size()) {

            int j = i;

            // Find the '#'
            while (store[j] != '#') {
                j++;
            }

            // Get the length
            int len = stoi(store.substr(i, j - i));

            // Start of actual string
            j++;

            // Extract the string
            decoded.push_back(store.substr(j, len));

            // Move to next encoded string
            i = j + len;
        }

        return decoded;
    }
};
