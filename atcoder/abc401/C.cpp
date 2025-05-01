#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <deque>

constexpr int64_t MOD = int64_t(1e9);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    if(N < K) {
        std::cout << 1 << '\n';
        return;
    }

    std::deque<int64_t> deq;
    int64_t sum = 0;
    int64_t now = 0;
    for(int i = 0; i < K; i++) {
        deq.push_back(1);
        sum += 1;
        sum %= MOD;
    }

    now = sum;
    for(int i = K; i <= N; i++) {
        sum -= deq.front();
        sum += MOD;
        sum %= MOD;
        sum += now;
        sum %= MOD;
        deq.pop_front();
        deq.push_back(now);
        now = sum;
    }

    std::cout << deq.back() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
