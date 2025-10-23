class Solution {
public:
    bool hasSameDigits(string s) {
        string digit = s;

        while (digit.size() > 2) {
            vector<int> nums(digit.size() - 1);

        
            for (int i = 1; i < digit.size(); i++) {
                int sum = (digit[i] - '0' + digit[i - 1] - '0') % 10;
                nums[i - 1] = sum;
            }

            // convert vector<int> -> string
            string temp;
            for (int num : nums) {
                temp += to_string(num);
            }
            digit = temp;
        }

        return digit[0] == digit[1];
    }
};
