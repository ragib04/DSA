//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
         int n=val.size();
        priority_queue<pair<double,int>>pq;

        for(int i=0;i<n;i++){
            pq.push({double((double)val[i]/(double)wt[i]),wt[i]});
        }
        double profit=0.0;
        while(capacity>0 &&!pq.empty()){
            int weight=pq.top().second;
            double unitprofit=pq.top().first;
            pq.pop();
            if(weight<=capacity){
                capacity-=weight;
                profit+=weight*unitprofit;
            }
            else{
                profit+=capacity*unitprofit;
                capacity=0;
            }
        }
        return profit;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends