class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            int freq[26] = {0};  

            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;

                int max_f = 0, min_f = INT_MAX;
                for (int f:freq) {
                    if (f> 0) {
                        max_f = max(max_f, f);
                        min_f = min(min_f, f);
                    }
                }
                sum += (max_f - min_f);
            }
        }

        return sum;
    }
};