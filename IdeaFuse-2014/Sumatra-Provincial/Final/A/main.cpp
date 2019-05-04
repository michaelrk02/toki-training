#include <iostream>
using namespace std;

int main() {
    int test; cin >> test;
    for (int t = 1; t <= test; t++) {
        int min = -1;
        int max = -1;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (i == 0) {
                min = x;
                max = x;
            }

            if (x < min) {
                min = x;
            }
            if (x > max) {
                max = x;
            }
        }
        cout << "Case #" << t << ": " << max - min << endl;
    }
    return 0;
}

