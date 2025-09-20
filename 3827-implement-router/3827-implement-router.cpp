//          TLE

// class Router {
// public:
// int memoryLimit;
// unordered_map<int, set<pair<int,int>>> src_desti_time;
// queue<pair<int, pair<int, int>>> q;

//     Router(int memoryLimit) {
//         this->memoryLimit = memoryLimit;
//     }
    
//     bool addPacket(int source, int destination, int timestamp) {

//         if(q.size() >= memoryLimit){
//             auto top = q.front();
//             q.pop();
//             src_desti_time[top.first].erase({top.second.first, top.second.second});
//             if(src_desti_time[top.first].empty()) {
//                 src_desti_time.erase(top.first);
//             }
//         }
           
        
//         if(src_desti_time.find(source) == src_desti_time.end())
//             return false;
//             src_desti_time[source].insert({destination, timestamp});
//         q.push({source, {destination, timestamp}});
//         return true;
        
//     }
    
//     vector<int> forwardPacket() {
//         vector<int> arr(3, -1); // default -1 if no packet
//         if(!q.empty()){
//             auto top = q.front();
//             arr[0] = top.first;                // source
//             arr[1] = top.second.first;         // destination
//             arr[2] = top.second.second;        // timestamp
            
//             q.pop();
//             src_desti_time[top.first].erase({top.second.first, top.second.second});
//             if(src_desti_time[top.first].empty()) {
//                 src_desti_time.erase(top.first);
//             }
//         }
//         return arr;
        
//     }
    
//     int getCount(int destination, int startTime, int endTime) {
//         int count = 0;
//     // Check all sources
//     for (auto &entry : src_desti_time) {
//         for (auto &p : entry.second) {
//             int dest = p.first;
//             int time = p.second;
//             if (dest == destination && time >= startTime && time <= endTime) {
//                 count++;
//             }
//         }
//     }
//     return count;
//     }
// };

// /**
//  * Your Router object will be instantiated and called as such:
//  * Router* obj = new Router(memoryLimit);
//  * bool param_1 = obj->addPacket(source,destination,timestamp);
//  * vector<int> param_2 = obj->forwardPacket();
//  * int param_3 = obj->getCount(destination,startTime,endTime);
//  */



class Router {
    using Packet = tuple<int,int,int>; 
    queue<Packet> q;
    set<Packet> st;  
    unordered_map<int, vector<int>> dl; 
    int lmt=0;

public:
    Router(int memoryLimit) {
        lmt = memoryLimit;
    }

    bool addPacket(int s, int d, int ts) {
        Packet t = {s,d,ts};
        if(st.count(t)) return false; 

        if(q.size() >= lmt) {
            st.erase(q.front());
            auto [a,b,c] = q.front();
            auto &vec = dl[b];
            if(!vec.empty() && vec.front() == c)
                vec.erase(vec.begin());
            q.pop();
        }
        q.push(t);
        st.insert(t);
        dl[d].push_back(ts); 
        return true;
    }

    vector<int> forwardPacket() {
        if(q.empty()) return {};
        auto [a,b,c] = q.front(); q.pop();
        st.erase({a,b,c});
        auto &vec = dl[b];
        auto it = lower_bound(vec.begin(), vec.end(), c);
        if(it != vec.end() && *it == c) vec.erase(it);

        return {a, b, c};
    }

    int getCount(int d, int s, int e) {
        auto &vec = dl[d];
        int l = lower_bound(vec.begin(), vec.end(), s) - vec.begin();
        int r = upper_bound(vec.begin(), vec.end(), e) - vec.begin();
        return r - l;
    }
};