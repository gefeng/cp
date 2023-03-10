#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int H, W, K;
    cin >> H >> W >> K;

    vector<string> G(H);
    for(int i = 0; i < H; i++) {
        cin >> G[i];
    }

    int ans = 0;
    for(int i = 0; i < (1 << H); i++) {
        for(int j = 0; j < (1 << W); j++) {
            int cnt = 0;

            for(int r = 0; r < H; r++) {
                for(int c = 0; c < W; c++) {
                    if((i & (1 << r)) || (j & (1 << c)) || G[r][c] == '.') {
                        continue;
                    }
                    cnt += 1;
                }
            }

            ans += cnt == K ? 1 : 0;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
