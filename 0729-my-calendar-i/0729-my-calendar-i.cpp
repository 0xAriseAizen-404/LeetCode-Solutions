class MyCalendar {
    vector<pair<int, int>> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto &x: bookings) {
            if (start < x.second && x.first < end)
                return false;
        }
        bookings.push_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */