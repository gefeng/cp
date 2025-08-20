#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K, L;
    std::cin >> N >> K >> L;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> safe;
    safe.push_back(0);
    
    for(int i = 0; i < N; i++) {
        if(A[i] + K <= L) {
            safe.push_back(i + 1);
        }
        if(A[i] > L) {
            std::cout << "No" << '\n';
            return;
        }
    }

    auto next_k = [&](int64_t now) {
        int64_t rem = now % (K << 1);   
        if(rem <= K) {
            return now + (K - rem);
        }
        return now + (K * 2 - rem) + K;
    };

    auto wait = [&](int64_t now, int64_t d) {
        int64_t rem = now % (K << 1);
        int64_t res = 0;
        if(rem < K) {
            if(rem + 1 <= d) {
                res = 1;
            } else {
                res = (K - rem) + K - d;
            }
        } else {
            if(K * 2 - rem <= d) {
                res = 1;
            } else {
                res = K * 2 - rem - d;
            }
        }
        return res;
    };
    
    auto valid = [&](int64_t now, int64_t d, int64_t delta) {
        int64_t rem = now % (K << 1);
        if(rem < K) {
            if(delta >= K - rem) {
                return d == K;
            }
            return rem + delta <= d;
        }

        if(delta <= K * 2 - rem) {
            return true;
        }

        return delta - (K * 2 - rem) <= d;
    };

    safe.push_back(N + 1);

    int n = safe.size();
    int64_t t = 0;
    for(int i = 0; i < n - 1; i++) {
        int l = safe[i];
        int r = safe[i + 1];

        t = next_k(t);
        for(int p = l + 1; p < r; p++) {
            int64_t d = L - A[p - 1];
            int64_t delta = wait(t, d);
            if(p - 1 == 0 || valid(t, L - A[p - 2], delta - 1)) {
                t += delta;
            } else {
                std::cout << "No" << '\n';
                return;
            }
        }
        t += 1;
    }

    std::cout << "Yes" << '\n';
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
