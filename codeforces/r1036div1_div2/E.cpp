#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));

    if(sum % 2 == 1) {
        std::cout << -1 << '\n';
        return;
    }

    int64_t max_v = *std::ranges::max_element(A);
    if(max_v > sum - max_v) {
        std::cout << -1 << '\n';
        return;
    }

    int64_t prefix = 0;
    int64_t suffix = 0;
    for(int i = 0; i < N - 1; i++) {
        prefix += A[i];
        suffix = sum - prefix;
        if(prefix == suffix) {
            std::cout << 1 << '\n';
            for(int j = 0; j < N; j++) {
                std::cout << A[j] << " \n"[j == N - 1];
            }
            return;
        }
    }

    prefix = A[0];
    suffix = 0;
    for(int i = 1; i < N - 1; i++) {
        if(A[i] == sum - A[i]) {
            std::cout << 2 << '\n';
            for(int j = 0; j < N; j++) {
                if(j < i) {
                    std::cout << A[j] << ' ';
                } else if(j == i) {
                    std::cout << prefix << ' ';
                } else {
                    std::cout << 0 << " \n"[j == N - 1];
                }
            }
            for(int j = 0; j < N; j++) {
                if(j < i) {
                    std::cout << 0 << ' ';
                } else if(j == i) {
                    std::cout << A[i] - prefix << ' ';
                } else {
                    std::cout << A[j] << " \n"[j == N - 1];
                }
            }
            return;
        }
        prefix += A[i];
    }

    prefix = A[0];
    suffix = 0;
    for(int i = 1; i < N - 1; i++) {
        if(prefix < sum / 2 && prefix + A[i] >= sum / 2) {
            std::cout << 2 << '\n';
            int64_t d = sum / 2 - prefix;
            int64_t t = sum - prefix - A[i] - d;
            for(int j = 0; j < N; j++) {
                if(j < i) {
                    std::cout << A[j] << ' ';
                } else if(j == i) {
                    std::cout << A[j] - d << ' ';
                    A[j] = d;
                } else {
                    int64_t x = std::min(t, A[j]);
                    t -= x;
                    A[j] -= x;
                    std::cout << x << " \n"[j == N - 1];
                }
            }
            for(int j = 0; j < N; j++) {
                if(j < i) {
                    std::cout << 0 << ' ';
                } else if(j == i) {
                    std::cout << A[j] << ' ';
                } else {
                    std::cout << A[j] << " \n"[j == N - 1];
                }
            }
            return;
        }

        prefix += A[i];
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
