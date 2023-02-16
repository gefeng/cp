#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const array<int, 4> DR{-1, 0, 1, 0};
const array<int, 4> DC{0, 1, 0, -1};

void run_case() {
    int H, W;
    cin >> H >> W;

    vector<string> G(H);
    for(int i = 0; i < H; i++) {
        cin >> G[i];
    }

    auto check = [&](char a, char b) -> int {
        int ans = 0;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(G[i][j] == a) {
                    int cnt = 0;
                    for(int d = 0; d < 4; d++) {
                        int ni = i + DR[d];
                        int nj = j + DC[d];
                        if(ni >= 0 && nj >= 0 && ni < H && nj < W && G[ni][nj] == b) {
                            cnt += 1;
                        }
                    }

                    if(cnt == 4) {
                        return 4;
                    }

                    if(cnt == 3) {
                        ans += 2;
                        continue;
                    }

                    for(int d = 0; d < 4; d++) {
                        bool ok = true;
                        for(int k = 0; k < 2; k++) {
                            int ni = i + DR[(d + k) % 4];
                            int nj = j + DC[(d + k) % 4];
                            if(ni < 0 || nj < 0 || ni >= H || nj > W || G[ni][nj] == a) {
                                ok = false;
                                break;
                            }
                        }
                        if(ok) {
                            ans += 1;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    };

    cout << check('#', '.') + check('.', '#') << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
