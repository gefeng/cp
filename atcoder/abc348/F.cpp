#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <bitset>

constexpr int MAX = 1000;

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<std::bitset<2000>> a(N);
    std::vector<std::bitset<2000>> b(MAX);
    for(int c = 0; c < M; c++) {
        for(int r = 0; r < N; r++) {
            b[A[r][c]].set(r);
        } 

        for(int r = 0; r < N; r++) {
            a[r] ^= b[A[r][c]];
        }

        for(int r = 0; r < N; r++) {
            b[A[r][c]].reset(r);
        }
    } 

    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans += a[i].count();
    }

    if(M % 2 == 1) {
        ans -= N;
    }

    std::cout << ans / 2 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
