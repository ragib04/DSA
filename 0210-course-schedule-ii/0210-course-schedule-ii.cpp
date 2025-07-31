class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i<prerequisites.size(); i++){
            int x = prerequisites[i][1];
            int y = prerequisites[i][0];
            adj[x].push_back(y);
        }
        vector<int>indegree(numCourses);
        for(int i = 0; i<numCourses; i++){
            for(auto j: adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> course;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            course.push_back(front);

            for(auto neighbour: adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) q.push(neighbour);
            }
        }
        if(course.size() == numCourses) return course;
        return {};
    }
};