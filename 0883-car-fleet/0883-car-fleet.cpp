class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> carSpeed;
        for (int i = 0; i < position.size(); i++) {
            carSpeed.push_back({position[i], (double) (target - position[i]) / speed[i]});
        }
        sort(carSpeed.begin(), carSpeed.end());
        int carFleet = 0;
        double minTime = carSpeed[carSpeed.size() - 1].second;
        for (int i = carSpeed.size() - 1; i >= 0; i--) {
            if (carSpeed[i].second > minTime) {
                carFleet++;
                minTime = carSpeed[i].second;
            }
        }
        carFleet++;
        //  0    2   4   6   8  10  12  14
        // 25   49  96  44  99  73  66  89
        // If the prio position take less time -> fleet
        return carFleet;
    }
};

// class Solution {
// public:
//     struct Car {
//         int position;
//         double time;
//     };
//     int carFleet(int target, vector<int>& position, vector<int>& speed) {
//         int n = position.size();
//         Car cars[n];
//         for (int i = 0; i < n; ++i) {
//             cars[i].position = position[i];
//             cars[i].time = (double)(target - position[i]) / speed[i];
//         }
//         sort(cars, cars + n, [](const Car& a, const Car& b) { 
//             return a.position > b.position; 
//         });
//         int fleet = 0;
//         double prevTime = 0;
//         for (int i = 0; i < n; ++i) {
//             if (cars[i].time > prevTime) {
//                 fleet++;
//                 prevTime = cars[i].time;
//             }
//         }
//         return fleet;
//     }
// };
