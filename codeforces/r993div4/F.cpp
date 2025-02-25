#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(2e5);

void run_case() {
    int N, M, Q;
    std::cin >> N >> M >> Q;
    
    std::vector<int> A(N);
    std::vector<int> B(M);
    
    int64_t sum_a = 0;
    int64_t sum_b = 0;
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum_a += A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
        sum_b += B[i];
    }

    std::vector<int64_t> s_a((MAX << 1) + 1, 0);
    std::vector<int64_t> s_b((MAX << 1) + 1, 0);
    for(int i = 0; i < N; i++) {
        if(std::abs(sum_a - A[i]) <= MAX) {
            s_a[sum_a - A[i] + MAX] = 1;
        }
    }
    
    for(int i = 0; i < M; i++) {
        if(std::abs(sum_b - B[i]) <= MAX) {
            s_b[sum_b - B[i] + MAX] = 1;
        }
    }

    for(int i = 0; i < Q; i++) {
        int64_t X;
        std::cin >> X;
        
        if(X == 0) {
            std::cout << (s_a[MAX] || s_b[MAX] ? "Yes" : "No") << '\n';
            continue;
        }
        
        int64_t x = std::abs(X);
        bool ok = false;
        for(int64_t f_1 = 1; f_1 * f_1 <= x; f_1++) {
            if(x % f_1 == 0) {
                int64_t f_2 = x / f_1;
                if(X >= 0) {
                    for(int _{}; _ < 2; _++) {
                        std::swap(f_1, f_2);
                        if(s_a[f_1 + MAX] && s_b[f_2 + MAX]) {
                            ok = true;      
                        }
                        if(s_a[-f_1 + MAX] && s_b[-f_2 + MAX]) {
                            ok = true;
                        }
                    }
                } else {
                    for(int _{}; _ < 2; _++) {
                        std::swap(f_1, f_2);
                        if(s_a[-f_1 + MAX] && s_b[f_2 + MAX]) {
                            ok = true;      
                        }
                        if(s_a[f_1 + MAX] && s_b[-f_2 + MAX]) {
                            ok = true;
                        }
                    }
                }
            }
        }

        std::cout << (ok ? "Yes" : "No") << '\n';
    } 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
