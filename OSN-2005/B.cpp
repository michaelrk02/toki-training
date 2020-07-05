// B - Kata Spiral
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

struct rect_t {
    int left, top;
    int right, bottom;
};

enum dir_t {
    DIR_RIGHT,
    DIR_DOWN,
    DIR_LEFT,
    DIR_UP
};

rect_t get_rect(const string &str) {
    rect_t rc;
    memset(&rc, 0, sizeof(rect_t));

    dir_t dir = DIR_RIGHT;
    int x = 0;
    int y = 0;
    for (int i = 0; i < str.size(); i++) {
        if (dir == DIR_RIGHT) {
            if (x > rc.right) {
                rc.right++;
                dir = DIR_DOWN;
                y++;
            } else {
                x++;
            }
        } else if (dir == DIR_DOWN) {
            if (y > rc.bottom) {
                rc.bottom++;
                dir = DIR_LEFT;
                x--;
            } else {
                y++;
            }
        } else if (dir == DIR_LEFT) {
            if (x < rc.left) {
                rc.left--;
                dir = DIR_UP;
                y--;
            } else {
                x--;
            }
        } else if (dir == DIR_UP) {
            if (y < rc.top) {
                rc.top--;
                dir = DIR_RIGHT;
                x++;
            } else {
                y--;
            }
        }
    }

    return rc;
}

int main() {
    string inp;
    getline(cin, inp);

    rect_t rc = get_rect(inp);
    int w = rc.right - rc.left + 1;
    int h = rc.bottom - rc.top + 1;

    char *spiral = new char[w * h + 1];
    spiral[w * h] = 0;

    dir_t dir = DIR_RIGHT;
    int x = -rc.left;
    int y = -rc.top;
    rc.left = x;
    rc.top = y;
    rc.right = x;
    rc.bottom = y;
    for (int i = 0; i < w * h; i++) {
        char ch = '_';
        if (i < inp.size()) {
            if (inp[i] != ' ') {
                ch = inp[i];
            }
        }
        spiral[y * w + x] = ch;

        if (dir == DIR_RIGHT) {
            if (x > rc.right) {
                rc.right++;
                dir = DIR_DOWN;
                y++;
            } else {
                x++;
            }
        } else if (dir == DIR_DOWN) {
            if (y > rc.bottom) {
                rc.bottom++;
                dir = DIR_LEFT;
                x--;
            } else {
                y++;
            }
        } else if (dir == DIR_LEFT) {
            if (x < rc.left) {
                rc.left--;
                dir = DIR_UP;
                y--;
            } else {
                x--;
            }
        } else if (dir == DIR_UP) {
            if (y < rc.top) {
                rc.top--;
                dir = DIR_RIGHT;
                x++;
            } else {
                y--;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << spiral[i * w + j];
        }
        cout << endl;
    }

    delete[] spiral;

    return 0;
}
