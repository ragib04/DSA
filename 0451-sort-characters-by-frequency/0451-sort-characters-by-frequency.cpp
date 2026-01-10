class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char ch: s){
            mp[ch]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});
        }
        string res = "";
        while(!pq.empty()){
            int cnt = pq.top().first;
            char ch = pq.top().second;
            while(cnt){
                res += ch;
                cnt--;
            }
            pq.pop();
        }
        return res;
    }
};