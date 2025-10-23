#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <ranges>
#include <numeric>

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

    if(N < M) {
        std::swap(A, B);
        std::swap(N, M);
    }


    int64_t ans = 0;
    std::ranges::sort(A);
    std::ranges::sort(B);
    std::map<int, int> ma; 
    std::map<int, int> mb;
    
    for(int i = 0; i < N; i++) {
        ma[A[i]] += 1;
    }
    
    for(int i = 0; i < M; i++) {
        mb[B[i]] += 1;
    }

    for(auto [x, f1] : ma) {
        if(mb.find(x) == mb.end()) {
            continue;
        }
        int f2 = mb[x];
        if(f1 + f2 > N) {
            for(int i = 0; i < N; i++) {
                if(A[i] != x) {
                    ans += A[i] + x;
                }
            } 
            for(int i = 0; i < M; i++) {
                if(B[i] != x) {
                    ans += B[i] + x;
                }
            }
            std::cout << ans << '\n';
            return;
        }
    }

    ans = std::accumulate(B.begin(), B.end(), static_cast<int64_t>(0));
    
    ma.clear();
    int picked = 0;
    for(int i = N - 1; i >= 0; i--) {
        int a = ma.find(A[i]) == ma.end() ? 0 : ma[A[i]];
        int b = mb.find(A[i]) == mb.end() ? 0 : mb[A[i]];

        if(a + b + 1 > M) {
            continue;
        }
        ans += A[i];
        ma[A[i]] += 1;
        picked += 1;
        if(picked == M) {
            break;
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
