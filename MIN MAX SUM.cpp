#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void miniMaxSum(vector<long> arr) {
    sort(arr.begin(), arr.end());
    long minSum = 0, maxSum = 0;

    // Calculate minimum sum (sum of first four elements)
    for (int i = 0; i < 4; ++i) {
        minSum += arr[i];
    }

    // Calculate maximum sum (sum of last four elements)
    for (int i = 1; i < 5; ++i) {
        maxSum += arr[i];
    }

    cout << minSum << " " << maxSum << endl;
}

int main() {
    vector<long> arr(5);

    for (int i = 0; i < 5; ++i) {
        cin >> arr[i];
    }

    miniMaxSum(arr);

    return 0;
}
