class Solution {
public:
    // Function to check if 'val' candies can be given to at least 'k' children
    bool solve(vector<int>& candies, long long k, int val) {
        long long total_pieces = 0; // Total pieces we can create

        for (int i = 0; i < candies.size(); i++) {
            if (val > candies[i]) {
                continue; // Skip if current candy count is less than 'val'
            } else {
                total_pieces += candies[i] / val; // Count how many pieces we can create
            }
        }

        return total_pieces >= k; // Return true if we can distribute enough pieces
    }

    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(), candies.end()); // Sort candies array
        int start = 1;                         // Minimum possible candy count per child
        int end = candies[candies.size() - 1]; // Maximum possible candy count per child
        int answer = 0;                        // Store the maximum valid answer

        // Binary Search to find the maximum valid number of candies per child
        while (start <= end) {
            int mid = (start + end) / 2; // Midpoint for binary search

            if (solve(candies, k, mid)) {
                answer = mid; // Store the valid value
                start = mid + 1; // Try for a bigger value
            } else {
                end = mid - 1; // Try for a smaller value
            }
        }

        return answer; // Return the maximum valid answer
    }
};