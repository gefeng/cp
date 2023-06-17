#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    LL ans = 0LL;
    int max_v = sqrt(2 * N);
    std::vector<std::vector<int>> cnt(max_v + 1, std::vector<int>(N + 1, 0));
    for(int i = 0; i < N; i++) {
        if(A[i] <= max_v) {
            for(int j = 1; j <= max_v; j++) {
                int x = A[i] * j - B[i];
                if(x >= 1 && x <= N) {
                    ans += cnt[j][x];
                }
            }
            cnt[A[i]][B[i]] += 1;
        }
    }

    for(int i = 0; i < N; i++) {
        if(A[i] > max_v) {
            for(int j = 1; j <= max_v; j++) {
                int x = A[i] * j - B[i];
                if(x >= 1 && x <= N) {
                    ans += cnt[j][x];
                }
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
