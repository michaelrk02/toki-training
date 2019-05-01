#include <iostream>
#include <cstdlib>
using namespace std;

typedef long long llong;

int main() {
    int tests; cin >> tests;
    for (int t = 1; t <= tests; t++) {
        llong x, y;
        cin >> x >> y;

        llong steps = abs(x - y) / 12;
        llong dx = 7 * steps;
        llong dy = 5 * steps;
        llong x1 = x + dx;
        llong y1 = y - dy;
        bool yaz = (x1 == y1);

        cout << "Case #" << t << ": ";
        if (yaz) {
            cout << x1;
        } else {
            cout << "impossible";
        }
        cout << endl;
    }
    return 0;
}

