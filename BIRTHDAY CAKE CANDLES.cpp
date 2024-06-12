#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int birthdayCakeCandles(vector<int> candles) {
    // Find the maximum height of candles
    int maxHeight = *max_element(candles.begin(), candles.end());
    
    // Count the number of candles with maximum height
    int count = count_if(candles.begin(), candles.end(), [&](int candle) {
        return candle == maxHeight;
    });
    
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> candles(n);
    for (int i = 0; i < n; ++i) {
        cin >> candles[i];
    }
    
    int result = birthdayCakeCandles(candles);
    cout << result << endl;
    
    return 0;
}
