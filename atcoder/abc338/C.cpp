#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 1e6;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> Q(N);
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> Q[i];
    }
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int ans = 0;
    for(int i = 0; i <= MAX; i++) {
        bool ok = true;
        int cnt_b = MAX;
        for(int j = 0; j < N; j++) {
            if((int64_t)A[j] * i > Q[j]) {
                ok = false;
                break;
            }
            if(B[j]) {
                cnt_b = std::min(cnt_b, (Q[j] - A[j] * i) / B[j]);
            }
        }

        if(ok) {
            ans = std::max(ans, cnt_b + i);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
