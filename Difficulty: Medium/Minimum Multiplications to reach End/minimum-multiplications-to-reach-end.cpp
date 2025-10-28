// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end) return 0;
        int mod = 100000;
        vector<int> dist(100000, 1e9);
        queue<pair<int, int>> q;
        dist[start] = 0;
        q.push({0, start});
        
        while(!q.empty()){
            int node = q.front().second;
            int step = q.front().first;
            q.pop();
            for(auto it: arr){
                int num = (it*node)%mod;
                if(step+1<dist[num]){
                    dist[num] = step+1;
                    if(num == end) return step+1;
                q.push({step+1, num});
                }
            
            }
        }
        return -1;
    }
};
