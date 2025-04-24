#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::vector<int> suffix(N + 1, 0);
    for(int i = 1, j = M - 1; i <= N; i++) {
        if(j < 0) {
            suffix[i] = M;
            continue;
        }
        if(A[N - i] >= B[j]) {
            suffix[i] = suffix[i - 1] + 1;
            j -= 1;
        } else {
            suffix[i] = suffix[i - 1];
        }
    }

    if(suffix[N] == M) {
        std::cout << 0 << '\n';
        return;
    }

    int prefix = 0;
    int ans = INF;
    for(int i = 0, j = 0; i <= N; i++) {
        if(j == M) {
            std::cout << 0 << '\n';
            return;
        }

        if(i && A[i - 1] >= B[j]) {
            j += 1;
            prefix += 1;
        }

        if(suffix[N - i] + prefix + 1 >= M) {
            ans = std::min(ans, B[j]);
        }
    }

    if(prefix == M) {
        std::cout << 0 << '\n';
        return;
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
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
