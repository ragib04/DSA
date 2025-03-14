//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int collectchoco(int i, int j1, int j2,int r,int c, vector<vector<int>>& grid,vector<vector<vector<int>>>&dp)
  {
     
        // out of the grid
        if(j1<0 || j1>=c|| j2<0 || j2>=c ) return -1e9;
        
        // destination best case
        if(i==r-1)
        {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        
        int maxxi = -1e8;
        
        // covering all 9 different case here
        for(int dj1=-1; dj1<=1; dj1++)
        {
            for(int dj2=-1;dj2<=1; dj2++)
            {
                int value = 0;
                
                if(j1==j2)  value = grid[i][j1];
                else  value = grid[i][j1]+grid[i][j2];
                 
                value+= collectchoco(i+1, j1+dj1, j2+dj2, r, c, grid,dp);
                 
                maxxi = max(maxxi,value);
            }
        }
        
        return dp[i][j1][j2] = maxxi;
        
  }
  
    int solve(int n, int m, vector<vector<int>>& grid) {
    
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return collectchoco(0,0,m-1,n,m,grid,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends