#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(int N, std::vector<int>& psum, int64_t x) {
    if(x <= N) {
        return psum[x] ^ psum[x - 1];
    }
    if(x / 2 <= N) {
        return psum[x / 2];
    }

    int64_t m = x / 2;
    if(N + 1 == m) {
        return psum[N] ^ dfs(N, psum, m);
    }

    if((N + 1) % 2 == 0) {
        if(m % 2 == 0) {
            return psum[N] ^ dfs(N, psum, m);
        } else {
            return psum[N];
        }
    } else {
        if(m % 2 == 0) {
            return psum[N] ^ dfs(N, psum, N + 1) ^ dfs(N, psum, m);
        } else {
            return psum[N] ^ dfs(N, psum, N + 1);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    int64_t L, R;
    std::cin >> L >> R;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] ^ A[i];
    }

    std::cout << dfs(N, psum, L) << '\n';
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
