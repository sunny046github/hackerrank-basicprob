
#include <iostream>

using namespace std;

// Function to check if a number is a power of 2
bool isPowerOfTwo(long long n) {
    return n && (!(n & (n - 1)));
}

string counterGame(long long n) {
    bool louiseTurn = true;

    while (n > 1) {
        if (isPowerOfTwo(n)) {
            // If n is a power of 2, divide by 2
            n /= 2;
        } else {
            // Find the largest power of 2 less than n and subtract it
            long long largestPowerOfTwo = 1;
            while (largestPowerOfTwo * 2 < n) {
                largestPowerOfTwo *= 2;
            }
            n -= largestPowerOfTwo;
        }
        // Toggle turn
        louiseTurn = !louiseTurn;
    }

    // If it's Louise's turn, Richard wins. Otherwise, Louise wins.
    return louiseTurn ? "Richard" : "Louise";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        cout << counterGame(n) << endl;
    }

    return 0;
}
