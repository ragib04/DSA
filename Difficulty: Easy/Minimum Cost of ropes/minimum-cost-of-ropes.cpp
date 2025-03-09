//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // code here
        int cost = 0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int &num: arr){
            pq.push(num);
        }
        while(pq.size() >= 2){
            int first = pq.top();
            pq.pop();
            int sec = pq.top();
            pq.pop();
            cost = cost + first +sec;
            pq.push(first+sec);
        }
        return cost;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends