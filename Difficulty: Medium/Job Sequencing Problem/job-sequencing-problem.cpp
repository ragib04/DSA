//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        int n = deadline.size();
        int cnt = 0;
         int maxprofit = 0;
         priority_queue<int, vector<int>, greater<int>> pq;
         vector<int> ans;
         vector<pair<int, int>> v;
         for(int i =0; i<n; i++){
             v.push_back({deadline[i], profit[i]});
             
         }
         sort(v.begin(), v.end());
         for(auto it:v){
             int d= it.first;
             int currprofit = it.second;
             
             if(d>cnt){
                 maxprofit += currprofit;
                 pq.push(currprofit);
                 cnt++;
                 
             }
             else{
                 if(d==cnt){
                     if(!pq.empty() && currprofit>pq.top()){
                         maxprofit -= pq.top();
                         pq.pop();
                         maxprofit += currprofit;
                         pq.push(currprofit);
                     }
                 }
             }
         }
             ans.push_back(cnt);
             ans.push_back(maxprofit);
             return ans;
             
         
        
    }
};


//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
