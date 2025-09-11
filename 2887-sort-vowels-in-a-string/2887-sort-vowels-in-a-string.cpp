class Solution {
public:
    bool isvowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string sortVowels(string s) {
        vector<char> arr;
        int n = s.size();
        for (auto c : s) {
            if (isvowel(c)) {

                arr.push_back(c);
            }
        }
        sort(arr.begin(), arr.end());

        int idx = 0;
        for (int i = 0; i<n; i++) {
            if (isvowel(s[i])) {
                s[i] = arr[idx];
                idx++;
            }
        }
        return s;
    }
};

