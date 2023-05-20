#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
        B[i] = A[i];
    }

    std::sort(B.begin(), B.end());

    std::vector<std::vector<int>> cnt(4, std::vector<int>(4, 0));
    for(int i = 0; i < N; i++) {
        if(A[i] != B[i]) {
            cnt[A[i]][B[i]] += 1;
        }
    }

    int ans = 0;
    for(int a = 0; a < 4; a++) {
        for(int b = 0; b < 4; b++) {
            if(a != b) {
                int v = std::min(cnt[a][b], cnt[b][a]);
                cnt[a][b] -= v;
                cnt[b][a] -= v;
                ans += v;
            }
        }
    }

    for(int a = 0; a < 4; a++) {
        for(int b = 0; b < 4; b++) {
            for(int c = 0; c < 4; c++) {
                if(a != b && b != c && a != c) {
                    int v = std::min(std::min(cnt[a][b], cnt[b][c]), cnt[c][a]);
                    cnt[a][b] -= v;
                    cnt[b][c] -= v;
                    cnt[c][a] -= v;
                    ans += v * 2;
                }
            }
        }
    }

    int tot = 0;
    for(int a = 0; a < 4; a++) {
        for(int b = 0; b < 4; b++) {
            tot += cnt[a][b];
        }
    }

    ans += tot / 4 * 3;
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
