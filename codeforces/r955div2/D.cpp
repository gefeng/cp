#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    std::vector<std::string> G(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
    }
    
    int64_t sum_0 = 0;
    int64_t sum_1 = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(G[i][j] == '0') {
                sum_0 += A[i][j];
            } else {
                sum_1 += A[i][j];
            }
        }
    }

    if(sum_0 == sum_1) {
        std::cout << "Yes" << '\n';
        return;
    }

    std::vector<std::vector<int>> psum(N + 1, std::vector<int>(M + 1, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            psum[i + 1][j + 1] = psum[i + 1][j] + psum[i][j + 1] - psum[i][j] + (G[i][j] - '0');
        }
    }

    std::vector<int> a;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int x = i - K + 1;
            int y = j - K + 1;
            if(x >= 0 && y >= 0 && x < N && y < M) {
                int cnt = psum[i + 1][j + 1] - psum[i + 1][y] - psum[x][j + 1] + psum[x][y];
                int d = std::abs(cnt - (K * K - cnt));
                if(d == 0) {
                    continue;
                }
                a.push_back(d);
            }
        }
    }

    if(a.empty()) {
        std::cout << "No" << '\n';
        return;
    }


    int64_t t = std::abs(sum_0 - sum_1);
    for(int x : a) {
        if(t % x == 0) {
            std::cout << "Yes" << '\n';
            return;
        }
    }
    
    int g = a[0];
    for(int x : a) {
        g = gcd(g, x);
    }
    
    std::cout << (t % g == 0 ? "Yes" : "No") << '\n';
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
