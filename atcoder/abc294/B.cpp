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

    vector<string> ans(H);
    for(int i = 0; i < H; i++) {
        string s = "";
        for(int j = 0; j < W; j++) {
            int X;
            cin >> X;

            if(X == 0) {
                s.push_back('.');
            } else {
                s.push_back((char)(X - 1 + 'A'));
            }
        }

        ans[i] = s;
    }

    for(int i = 0; i < H; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
