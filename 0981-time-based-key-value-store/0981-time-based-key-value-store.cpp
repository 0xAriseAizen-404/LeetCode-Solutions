class TimeMap {
private:
    map<string, vector<pair<string, int>>> hMap;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hMap[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        if (hMap.find(key) == hMap.end()) {
            return "";
        }

        vector<pair<string, int>>& list = hMap[key];

        int low = 0;
        int high = list.size() - 1;

        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (list[mid].second <= timestamp) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return list[low].second <= timestamp ? list[low].first : "";
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */