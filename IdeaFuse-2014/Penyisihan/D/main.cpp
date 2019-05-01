#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int test; cin >> test;
    for (int t = 0; t < test; t++) {
        int c; cin >> c;
        int x = 1 + sqrt(2 * c - 1);
        cout << x << endl;
    }
    return 0;
}

