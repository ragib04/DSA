class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char ch: s){
            mp[ch]++;
        
        }
        priority_queue<pair<int, char>> pq;
        for(auto ch: mp){
            pq.push({ch.second, ch.first});
        }
        string ans = "";
        while(!pq.empty()){
            int top = pq.top().first;
            while(top--){
                ans += pq.top().second;
            }
            pq.pop();
        }
        return ans;
    }
};