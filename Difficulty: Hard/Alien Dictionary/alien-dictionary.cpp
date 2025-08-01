class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int V = words.size();
        vector<int> adj[26];
        vector<bool> exists(26, false);
        for (int i=0; i<words.size(); i++) {
            for (char ch : words[i]) {
                exists[ch - 'a'] = true;
            }
        }
        for(int i=0; i<V-1; i++){
            string str1 = words[i];
            string str2 = words[i+1];
            int j=0;
            while(j<str1.size() && j<str2.size() && str1[j] == str2[j]){
                j++;
            }
            if(j!= str1.size() && j == str2.size()){
                return "";
            }
            
            if (j < str1.size() && j < str2.size()) {
                adj[str1[j] - 'a'].push_back(str2[j] - 'a');
            }
        }
        
        vector<int>indegree(26,0);
        for(int i=0; i<26; i++){
            for(int j=0; j<adj[i].size(); j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0; i<26; i++){
            if(exists[i] && indegree[i] == 0){
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans += node + 'a';
            for(int j=0; j<adj[node].size(); j++){
                indegree[adj[node][j]]--;
                if(indegree[adj[node][j]] == 0){
                    q.push(adj[node][j]);
                }
            }
        }
        
        for(int i=0; i<26; i++){
            if(indegree[i] != 0){
                return "";
            }
        }
        
        return ans;
    }
};