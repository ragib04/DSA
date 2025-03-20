//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
  
//         vector<vector<int>> findAllSubsetsSum(vector<int>& nums, int l, int r) {
//     int totLengthOfSubarray = r - l + 1;
//     vector<vector<int>> res(totLengthOfSubarray + 1);
//     for (int i = 0; i < (1 << totLengthOfSubarray); i++) {
//         int sum = 0, countOfChosenNos = 0;
//         for (int j = 0; j < totLengthOfSubarray; j++) {
//             if (i & (1 << j)) {
//                 sum += nums[l + j];
//                 countOfChosenNos++;
//             }
//         }
//         res[countOfChosenNos].push_back(sum);
//     }
//     return res;
// }
    int minDifference(vector<int>& arr) {


    
    int n = arr.size();
  int sum = 0;
	    for(int i = 0; i<n; i++) sum+=arr[i];
	    int t[n+1][sum+1];
	    
	    for(int i = 0; i<n+1; i++){
	        for(int j = 0; j<sum+1; j++){

	            if(i == 0) t[i][j] = 0; 
	            if(j==0) t[i][j] = 1;
	        }
	    }
	    //Filling up the table
	    for(int i = 1; i<n+1; i++){
	        for(int j = 1; j<sum+1; j++){
	            if(arr[i-1] <= j){
	                t[i][j] = (t[i-1][j-arr[i-1]] || t[i-1][j]);
	            }
	            else{
	                t[i][j] = t[i-1][j];
	            }
	        }
	    }
	    int ans = INT_MAX;
//All the subset sum which is possible for this n sized array will have true value in table in nth row
	    for(int j = 0; j<sum+1; j++)//Iterating last row where the sum exists
	    {
// abs(sum - 2*(subset_sum) will give subset sum difference
	        if(t[n][j] == 1) ans = min(ans, abs(sum - 2*j));
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