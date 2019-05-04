#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int test; cin >> test;
    for (int t = 1; t <= test; t++) {
        int n; cin >> n;;
        vector<string> words;
        while (true) {
            string w; cin >> w;
            if (!w.compare("END")) {
                break;
            }
            words.push_back(w);
        }

        cout << "Case #" << t << ":" << endl;
        int lcch = 0;
        for (int i = 0; i < words.size(); i++) {
            int wcch = words[i].length();
            if (lcch == 0) {
                cout << words[i];
                lcch += wcch;
                continue;
            }
            if (lcch + wcch + 1 <= n) {
                cout << ' ' << words[i];
                lcch += wcch + 1;
            } else {
                cout << endl << words[i];
                lcch = wcch;
            }
            if (i == words.size() - 1) {
                cout << endl;
            }
        }
    }

    return 0;
}

