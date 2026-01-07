class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        map<int, int> mp;
        for(auto it: arr){
            mp[it]++;
            
        }
        priority_queue<pair<int, int>> pq;
        for(auto it: mp){
            pq.push({it.second, -it.first});
        }
        vector<int> ans;
        while(!pq.empty()){
            int freq = pq.top().first;
            int ele = pq.top().second;
            while(freq>0){
                ans.push_back(-(ele));
                freq--;
            }
            pq.pop();
        }
        
        return ans;
        
    }
};