class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        while (n > 2) {
            for (int i = 1; i < s.size(); i++) {
                int sum = (s[i] - '0' + s[i - 1] - '0') % 10;
                //s[i - 1] = to_string(sum);
                s[i - 1] = char('0' + sum);
            }
            // dec the s size by 1
            n--;
        }

        return s[0] == s[1];
    }
};
