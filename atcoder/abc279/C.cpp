#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int H, W;
    cin >> H >> W;
    
    vector<string> S(H);
    vector<string> T(H);

    for(int i = 0; i < H; i++) {
        cin >> S[i];
    }

    for(int i = 0; i < H; i++) {
        cin >> T[i];
    }

    for(int i = 0; i < H; i++) {
        int cnt = 0;
        for(char c : S[i]) {
            cnt += c == '#' ? 1 : 0;
        }
        for(char c : T[i]) {
            cnt -= c == '#' ? 1 : 0;
        }

        if(cnt != 0) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
