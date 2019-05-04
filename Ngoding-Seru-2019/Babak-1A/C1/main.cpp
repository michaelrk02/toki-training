#include <iostream>
#include <vector>

using namespace std;

int64_t gcd(int64_t a, int64_t b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int64_t gcd_v(const vector<int64_t>& arr) {
    
}

int64_t beauty(const vector<int64_t>& arr, int left, int right) {
}

