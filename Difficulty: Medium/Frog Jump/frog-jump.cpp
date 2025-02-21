//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  /*
  
  ////.  memoization--->>>>>>
  
  int f(int n, vector<int> &height, vector<int> dp){
      if(n == 0) return 0;
      if(dp[n] != -1) return dp[n];
      int left = f(n-1, height, dp) + abs(height[n]-height[n-1]);
      int right = INT_MAX;
      if(n>1) right = f(n-2, height, dp) + abs(height[n]-height[n-2]);
      
      dp[n] = min(left, right);
      return dp[n];
  }*/
 

    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        // vector<int> dp(ind+1);
       // return f(ind-1, height, dp);  //memoization
       
       vector<int>ans(n,0);
        ans[0]=0;
        if(n==1)return 0;
        ans[1]=abs(height[0]-height[1]);
        for(int i = 2 ; i < n ; i++){
            int a = ans[i-1] + abs(height[i]-height[i-1]);
            int b = ans[i-2] + abs(height[i]-height[i-2]);
            ans[i]=min(a,b);
        }
        return ans[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends