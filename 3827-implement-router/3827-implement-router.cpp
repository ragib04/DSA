class Router {
public:
int maxSize;

string MakeKey(int src, int dest, int timestamp){
    return to_string(src)+"_"+to_string(dest)+"_"+to_string(timestamp);
}

    Router(int memoryLimit) {
        maxSize = memoryLimit;
    }
    unordered_map<int, vector<int>> destTimestamp;
    unordered_map<string, vector<int>> storePacket;
    queue<string> q;
    bool addPacket(int source, int destination, int timestamp) {
        string key = MakeKey(source, destination, timestamp);
        if(storePacket.find(key) != storePacket.end()) return false;
        if(q.size()>=maxSize){
            forwardPacket();
        }
        storePacket[key] = {source, destination, timestamp};
        q.push(key);
        destTimestamp[destination].push_back(timestamp);
        return true;

    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        string key = q.front();
        q.pop();
        vector<int> packet = storePacket[key];
        storePacket.erase(key);
        int dest = packet[1];
        destTimestamp[dest].erase(destTimestamp[dest].begin());

        return packet;
        
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamp.find(destination);
        if(it == destTimestamp.end() || it->second.empty()) return 0;

        int l = lower_bound(begin(it->second), end(it->second), startTime) - begin(it->second);
        int r = upper_bound(begin(it->second), end(it->second), endTime) - begin(it->second);

        return r-l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */