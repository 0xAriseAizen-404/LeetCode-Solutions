class RandomizedSet {
    vector<int> vals;
    unordered_map<int, int> mapp;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (mapp.find(val) != mapp.end()) return false;
        vals.push_back(val);
        mapp[val] = vals.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (mapp.find(val) == mapp.end()) return false;
        int idx = mapp[val];
        vals[idx] = vals.back();
        mapp[vals.back()] = idx;
        vals.pop_back();
        mapp.erase(val);
        return true;
    }
    
    int getRandom() {
        return vals[rand()%vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */