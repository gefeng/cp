#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> B(N);
    for(int i = 0; i < M; i++) {
        int K;
        std::cin >> K;
        for(int j = 0; j < K; j++) {
            int X;
            std::cin >> X;
            X -= 1;
            B[X].push_back(i);
        }
    }

    int n = int(std::pow(3, N));
    int64_t ans = INF; 
    for(int i = 1; i < n; i++) {
        std::vector<int> a;
        int x = i;
        while(a.size() != N) {
            a.push_back(x % 3);
            x /= 3; 
        }

        std::vector<int> freq(M, 0);
        int64_t cost = 0;
        for(int j = 0; j < N; j++) {
            for(int k : B[j]) {
                freq[k] += a[j] == 2 ? 2 : (a[j] == 1 ? 1 : 0);
            }
            if(a[j]) {
                cost += a[j] == 2 ? A[j] * 2 : (a[j] == 1 ? A[j] : 0);
            }
        }

        bool ok = true;
        for(int j = 0; j < M; j++) {
            if(freq[j] < 2) {
                ok = false;
            }
        }

        if(ok) {
            ans = std::min(ans, cost);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
