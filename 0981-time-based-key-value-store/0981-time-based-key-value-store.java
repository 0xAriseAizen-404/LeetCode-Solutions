class TimeMap {
    HashMap<String, List<Pair<String, Integer>>> hMap;
    public TimeMap() {
        hMap = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if(!hMap.containsKey(key)) hMap.put(key, new ArrayList<>());
        hMap.get(key).add(new Pair(value, timestamp));
    }
    
    public String get(String key, int timestamp) {
        if (!hMap.containsKey(key)) return "";
        List<Pair<String, Integer>> list = hMap.get(key);
        // Binary Search
        int low = 0;
        int high = list.size() - 1;
        while(low < high) {
            int mid = low + (high - low + 1) / 2;
            if(list.get(mid).getValue() <= timestamp) low = mid;
            else high = mid - 1;
        }
        return list.get(low).getValue() <= timestamp ? list.get(low).getKey() : "";
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */