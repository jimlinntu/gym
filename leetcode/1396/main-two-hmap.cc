
struct Avg{
    int acc;
    int n;
};

struct CheckIn{
    string name;
    int t;
};

struct Hasher{
    size_t operator()(const pair<string, string> &p) const{
        auto h = hash<string>();
        return (h(p.first) << 1) ^ h(p.second);
    }
};

class UndergroundSystem {
public:
    unordered_map<pair<string, string>, Avg, Hasher> map;
    unordered_map<int, CheckIn> track_enter;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        track_enter[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        // update
        CheckIn &c = track_enter[id];
        Avg &e = map[{c.name, stationName}];
        e.acc += t-c.t;
        e.n++;
        // destroy the checkin (or just leave it there)
        // track_enter.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        Avg &e = map[{startStation, endStation}];
        return (double)e.acc / e.n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
