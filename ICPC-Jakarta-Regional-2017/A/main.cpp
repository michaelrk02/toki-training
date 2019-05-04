#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> testCases(M);
    for (auto m = 0; m < M; m++) {
        cin >> testCases[m];
    }

    vector<int> solved(N);
    for (auto n = 0; n < N; n++) {
        int solvedTestCases = 0;
        for (auto m = 0; m < M; m++) {
            int Sj;
            cin >> Sj;

            if (Sj == testCases[m]) {
                solvedTestCases++;
            }
        }
        solved[n] = solvedTestCases;
    }

    auto maxIndex = 0;
    for (auto i = 0; i < N; i++) {
        if (solved[i] > solved[maxIndex]) {
            maxIndex = i;
        }
    }

    cout << (maxIndex + 1) << endl;

    return 0;
}

