
#include <iostream>

using namespace std;

void staircase(int n) {
    for (int i = 1; i <= n; ++i) {
        // Print spaces
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }
        // Print '#' symbols
        for (int k = 0; k < i; ++k) {
            cout << "#";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    staircase(n);
    return 0;
}

