#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

constexpr int MAX = 1e6;
 
std::vector<int> freq(MAX + 1, 0);
 
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
 
    int64_t sum_a = std::accumulate(A.begin(), A.end(), int64_t(0));
    int64_t sum_b = std::accumulate(B.begin(), B.end(), int64_t(0));
    
    if(sum_a < sum_b) {
        std::cout << -1 << '\n';
        return;
    }
 
    if(sum_a == sum_b) {
        std::sort(A.begin(), A.end());
        std::sort(B.begin(), B.end());
        for(int i = 0; i < N; i++) {
            if(A[i] != B[i]) {
                std::cout << -1 << '\n';
                return;
            }
        }
        std::cout << A.back() + 1 << '\n';
    } else {
        int64_t d = sum_a - sum_b;
        std::vector<int64_t> divisors;
        for(int64_t f = 1; f * f <= d; f++) {
            if(d % f == 0) {
                divisors.push_back(f);
                if(d / f != f) {
                    divisors.push_back(d / f);
                }
            }
        }
 
        for(int64_t x : divisors) {
            bool ok = true;
            for(int i = 0; i < N; i++) {
                freq[B[i]] += 1;
            }
 
            for(int i = 0; i < N; i++) {
                int t = A[i] % x;
                if(freq[t] == 0) {
                    ok = false;
                    break;
                }
                freq[t] -= 1;
            }
 
            for(int i = 0; i < N; i++) {
                freq[B[i]] = 0;
            }
 
            if(ok) {
                std::cout << x << '\n';
                return;
            }
        }
 
        std::cout << -1 << '\n';
    }
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
