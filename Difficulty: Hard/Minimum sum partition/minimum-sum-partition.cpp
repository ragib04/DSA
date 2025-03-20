//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n  = arr.size();
        int sum = 0;
        for(int i =0; i<n; i++) sum += arr[i];
        
        int dp[n+1][sum+1];
        //base case of subsetsum
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<sum+1; j++){
               //if(arr[0]<=sum)   = [0][a[0]] = true
               if(i == 0) dp[0][j] = 0;
               if(j==0) dp[i][0] = 1;       //if sum == 0 true;
            }
        }
        
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<sum+1; j++){
                if(arr[i-1]<=j){
                    //dp[i][j] = take || not_take
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                    
                }
                //is not in subset range
                else{
                    dp[i][j] = dp[i-1][j];//not take
                }
            }
        }
        
        int ans = INT_MAX;
        for(int j = 0; j<sum+1; j++){
            if(dp[n][j] == 1) ans = min(ans, abs(sum- (2*j)));
        }
       return ans; 
    }
};




//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
