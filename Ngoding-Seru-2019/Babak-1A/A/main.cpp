#include <iostream>
#include <stdint.h>

using namespace std;

#define DUMP(_X) cout << #_X << ": " << (_X) << endl

void getYBoundaries(int64_t px, int64_t py, int64_t x, int64_t& y1, int64_t& y2) {
    int64_t delta = x - px;
    y1 = py - delta;
    y2 = py + delta;
}

int main() {
    int64_t R, C, A, B, X, Y;
    cin >> R >> C >> A >> B >> X >> Y;

    int64_t y1, y2;
    getYBoundaries(A, B, X, y1, y2);

    bool can = false;
    if (X > A) { // only move downwards
        if ((y1 <= Y) && (Y <= y2)) { // check if it's in source's boundary
            if ((Y - y1) % 2 == 0) { // check the correct cell
                can = true;
            }
        }
    }

    cout << (can ? "YA" : "TIDAK") << endl;

    return 0;
}

