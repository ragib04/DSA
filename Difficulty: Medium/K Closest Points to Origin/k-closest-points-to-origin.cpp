//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
         auto calc_distance = [](int x, int y) {
            return round(sqrt(x * x + y * y) * 100.0) / 100.0; // rounding to 2 decimal places
        };

        // Map to store distances and the corresponding points
        map<double, vector<vector<int>>> pairs_with_distances;

        // Fill the map with points and their distances
        for (auto& point : points) {
            int x = point[0], y = point[1];
            double distance = calc_distance(x, y);
            pairs_with_distances[distance].push_back(point);
        }

        // Vector to store the result
        vector<vector<int>> res;

        // Iterate through the map to collect the k closest points
        for (auto& entry : pairs_with_distances) {
            for (auto& point : entry.second) {
                res.push_back(point);
                k--;
                if (k == 0) {
                    return res;
                }
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends