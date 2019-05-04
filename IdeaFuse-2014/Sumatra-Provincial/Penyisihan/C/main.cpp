#include <iostream>
#include <string>
using namespace std;

int** texels;
int rows, cols;

int topNeighbor(int r, int c) {
    if (r == 0) {
        return 0;
    }
    return texels[r - 1][c];
}

int leftNeighbor(int r, int c) {
    if (c == 0) {
        return 0;
    }
    return texels[r][c - 1];
}

int main() {
    cin >> rows >> cols;
    texels = new int*[rows];
    for (int i = 0; i < rows; i++) {
        texels[i] = new int[cols];
        string s; cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '1') {
                texels[i][j] = 1;
            } else {
                texels[i][j] = 0;
            }
        }
    }

    int bones = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (texels[i][j] == 1) {
                int tn = topNeighbor(i, j);
                int ln = leftNeighbor(i, j);
                if (tn == 0) {
                    bones += 1;
                }
                if (ln == 0) {
                    bones += 1;
                }
                bones += 2;
            }
        }
    }

    cout << bones << endl;

    return 0;
}

