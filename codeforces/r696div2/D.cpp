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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> rolling(N, 0);
    rolling[0] = A[0];
    bool ok = true;
    for(int i = 1; i < N; i++) {
        if(A[i] < rolling[i - 1]) {
            ok = false;
        }
        
        rolling[i] = A[i] - rolling[i - 1];
    }

    if(ok && rolling.back() == 0) {
        std::cout << "YES" << '\n';
        return;
    }

    std::vector<int64_t> min_eve(N, INF);
    std::vector<int64_t> min_odd(N, INF);
    
    for(int i = N - 1; i >= 0; i--) {
        if(i % 2 == 0) {
            min_eve[i] = i == N - 1 ? rolling[i] : std::min(min_eve[i + 1], rolling[i]);
            min_odd[i] = i == N - 1 ? min_odd[i] : min_odd[i + 1];
        } else {
            min_odd[i] = i == N - 1 ? rolling[i] : std::min(min_odd[i + 1], rolling[i]);
            min_eve[i] = i == N - 1 ? min_eve[i] : min_eve[i + 1];
        }
    }

    ok = true;
    for(int i = 0; i < N - 1; i++) {
        int64_t last = 0;
        if(i % 2 == 0) {
            int64_t delta_eve = int64_t(2) * (A[i + 1] - A[i]);
            int64_t delta_odd = int64_t(2) * (A[i] - A[i + 1]);
            if((N - 1) % 2 == 0) {
                last = rolling[N - 1] + delta_eve;
            } else {
                last = rolling[N - 1] + delta_odd;
            }
            if(ok && last == 0 && rolling[i] + A[i + 1] - A[i] >= 0 && min_eve[i + 1] + delta_eve >= 0 && min_odd[i + 1] + delta_odd >= 0) {
                std::cout << "YES" << '\n';
                return;
            } 
        } else {
            int64_t delta_eve = int64_t(2) * (A[i] - A[i + 1]);
            int64_t delta_odd = int64_t(2) * (A[i + 1] - A[i]);
            if((N - 1) % 2 == 0) {
                last = rolling[N - 1] + delta_eve;
            } else {
                last = rolling[N - 1] + delta_odd;
            }
            if(ok && last == 0 && rolling[i] + A[i + 1] - A[i] >= 0 && min_eve[i + 1] + delta_eve >= 0 && min_odd[i + 1] + delta_odd >= 0) {
                std::cout << "YES" << '\n';
                return;
            }
        }

        ok = ok && rolling[i] >= 0;
    }

    std::cout << "NO" << '\n';
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
