#include <iostream>
#include <string>

using namespace std;

string timeConversion(string s) {
    int hour = stoi(s.substr(0, 2));
    string period = s.substr(8, 2); // Get AM/PM part

    // If it's PM and not 12, convert to 24-hour format
    if (period == "PM" && hour != 12) {
        hour += 12;
    }

    // If it's AM and it's 12, convert to 24-hour format
    if (period == "AM" && hour == 12) {
        hour = 0;
    }

    // Format hour part to have leading zero if necessary
    string hourStr = (hour < 10) ? "0" + to_string(hour) : to_string(hour);

    return hourStr + s.substr(2, 6);
}

int main() {
    string s;
    cin >> s;

    string result = timeConversion(s);
    cout << result << endl;

    return 0;
}
