#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t MOD = int64_t(1e9) + 7;

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        } 
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::sort(A.begin(), A.end());

    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> pq;
    for(int64_t x : A) {
        pq.push(x);
    } 

    while(K) {
        int64_t x = pq.top();
        if(x * 2 > A.back()) {
            break;
        }

        pq.pop();
        x *= 2; 
        pq.push(x);
        K -= 1;
    }

    std::vector<int64_t> a;
    int64_t sum = 0;
    while(!pq.empty()) {
        a.push_back(pq.top());
        pq.pop();
        sum += a.back();
        sum %= MOD;
    }

    int64_t round = K / N;
    int64_t rem = K % N;
    
    int64_t mul = 1;
    if(round > 0) {
        mul = q_pow(2, round);
        for(int i = 0; i < N; i++) {
            sum += ((mul * a[i] % MOD) - a[i] + MOD) % MOD;
            sum %= MOD;
        }
    }

    for(int i = 0; i < rem; i++) {
        sum += mul * a[i] % MOD; 
        sum %= MOD;
    }
    
    std::cout << sum << '\n';
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
