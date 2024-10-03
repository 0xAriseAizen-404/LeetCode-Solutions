class Solution {
public:
    struct Car {
        int position;
        double time;
    };
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        Car cars[n];
        for (int i = 0; i < n; ++i) {
            cars[i].position = position[i];
            cars[i].time = (double)(target - position[i]) / speed[i];
        }
        sort(cars, cars + n, [](const Car& a, const Car& b) { 
            return a.position > b.position; 
        });
        int fleet = 0;
        double prevTime = 0;
        for (int i = 0; i < n; ++i) {
            if (cars[i].time > prevTime) {
                fleet++;
                prevTime = cars[i].time;
            }
        }
        return fleet;
    }
};
