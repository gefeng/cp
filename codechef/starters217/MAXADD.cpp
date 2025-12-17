#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    } 

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + B[i];
    }

    std::vector<int64_t> suffix(N, 0);
    std::vector<int> stk;
    for(int i = N - 1; i >= 0; i--) {
        while(!stk.empty() && A[stk.back()] - psum[stk.back() + 1] < A[i] - psum[i + 1]) {
            stk.pop_back();
        }

        suffix[i] = stk.empty() ? A[i] + psum[N] - psum[i + 1] : suffix[stk.back()];
        
        stk.push_back(i);
    }

    int64_t ans = 0;
    int64_t x = 1;
    int i = 0;
    while(x <= M) {
        if(i == N) {
            int64_t t = M - x + 1;
            ans += t * x + (M - x) * t / 2 + psum[N] * t;
            break;
        }
        
        while(i < N && psum[i + 1] + x > A[i]) {
            i += 1;
        }

        if(i == N) {
            ans += x + psum[N];
            x += 1;
            continue;
        }

        int64_t d = A[i] - psum[i + 1] - x + 1;
        d = std::min(d, M - x + 1);
        ans += suffix[i] * d;
        x += d;
        i += 1;
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
