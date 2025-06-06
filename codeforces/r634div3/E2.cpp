#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 200;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    std::vector<std::vector<int>> psum(MAX + 1, std::vector<int>(N + 1, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= MAX; j++) {
            psum[j][i + 1] = psum[j][i] + (j == A[i] ? 1 : 0);
            ans = std::max(ans, psum[j][i + 1]);
        }
    }

    std::vector<std::vector<int>> suffix(MAX + 1);
    std::vector<int> freq(MAX + 1, 0);
    
    for(int i = 1; i <= MAX; i++) {
        suffix[i].resize(psum[i][N] + 1, 0);
    }
    
    for(int i = N - 1; i >= 0; i--) {
        freq[A[i]] += 1;
        suffix[A[i]][freq[A[i]]] = i;
    }
    
    freq.assign(MAX + 1, 0);
    for(int i = 0; i < N; i++) {
        int f = ++freq[A[i]];
        int r = suffix[A[i]][f];
        if(r > i) {
            for(int j = 1; j <= MAX; j++) {
                if(j != A[i]) {
                    ans = std::max(ans, (f << 1) + psum[j][r] - psum[j][i + 1]);
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
