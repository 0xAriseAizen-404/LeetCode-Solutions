class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Not a Leap Year, same Calendar Year
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> preSum_months = {0};
        for (int days : months) {
            preSum_months.push_back(preSum_months.back() + days);
        }
         // Convert MM-DD into day of year (1 to 365)
        auto calculate_days = [&](string month_date) {
            int month = stoi(month_date.substr(0, 2));
            int days = stoi(month_date.substr(3, 2));
            return preSum_months[month - 1] + days;
        };
        // Let's encode the dates into 1 to 365, think of it like in ML Model
        int days_arriveAlice = calculate_days(arriveAlice);
        int days_leaveAlice = calculate_days(leaveAlice);
        int days_arriveBob = calculate_days(arriveBob);
        int days_leaveBob = calculate_days(leaveBob);
        // Overlap window is {Start, End} -> length "End - Start + 1"
        int start = max(days_arriveAlice, days_arriveBob);
        int end = min(days_leaveAlice, days_leaveBob);
        return max(0, end - start + 1);
    }
};