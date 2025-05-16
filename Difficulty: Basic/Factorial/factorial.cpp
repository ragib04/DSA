//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int fact(int n){
      if(n==0) return 1;
      
      return n* fact(n-1);
  }
    int factorial(int n) {
        // code here
        return fact(n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.factorial(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends