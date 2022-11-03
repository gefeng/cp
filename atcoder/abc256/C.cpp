#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

bool is_ok(int a, int b, int c, int d, array<int, 3>& H, array<int, 3>& W) {
    array<array<int, 3>, 3> g;
    g[0][0] = a;
    g[0][2] = b;
    g[2][0] = c;
    g[2][2] = d;

    g[0][1] = H[0] - a - b;
    g[2][1] = H[2] - c - d;
    g[1][0] = W[0] - a - c;
    g[1][2] = W[2] - b - d;

    g[1][1] = H[1] - g[1][0] - g[1][2];
    if(W[1] - g[0][1] - g[2][1] != g[1][1]) {
        return false;
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(g[i][j] <= 0) {
                return false;
            }
        }
    }

    return true;
}

void run_case() {
    array<int, 3> H{0};
    array<int, 3> W{0};

    int max_v = 0;
    for(int i = 0; i < 3; i++) {
        cin >> H[i];
        max_v = max(max_v, H[i]);
    }

    for(int i = 0; i < 3; i++) {
        cin >> W[i];
        max_v = max(max_v, W[i]);
    }
    
    int ans = 0;
    for(int a = 1; a < 30; a++) {
        for(int b = 1; b < 30; b++) {
            for(int c = 1; c < 30; c++) {
                for(int d = 1; d < 30; d++) {
                    if(is_ok(a, b, c, d, H, W)) {
                        ans += 1;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
