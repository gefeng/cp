#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

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
    int N, M;
    std::cin >> N >> M;

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(M);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::vector<int> pre(N, -1);
    std::vector<int> nxt(N, N);
    std::vector<int> stk;

    for(int i = N - 1; i >= 0; i--) {
        while(!stk.empty() && A[stk.back()] >= A[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            nxt[i] = stk.back();
        }
        stk.push_back(i);
    }

    stk.clear();
    for(int i = 0; i < N; i++) {
        while(!stk.empty() && A[stk.back()] > A[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            pre[i] = stk.back();
        }
        stk.push_back(i);
    }


    std::vector<std::pair<int64_t, int64_t>> a;
    for(int i = 0; i < N; i++) {
        a.emplace_back(A[i], static_cast<int64_t>(i - pre[i]) * (nxt[i] - i));
        a[i].second %= MOD;
    }

    std::ranges::sort(a);
    
    std::vector<int64_t> psum1(N + 1, 0);
    std::vector<int64_t> psum2(N + 1, 0);
    std::vector<int64_t> psum3(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum1[i + 1] = psum1[i] + (q_pow(a[i].first, MOD - 2) * a[i].second % MOD);
        psum1[i + 1] %= MOD;

        psum2[i + 1] = psum2[i] + a[i].second;
        psum2[i + 1] %= MOD;

        psum3[i + 1] = psum3[i] + (a[i].first * a[i].second % MOD);
        psum3[i + 1] %= MOD;
    }

    int64_t tot = 0;
    int64_t now = 0;
    for(int i = 0; i < N; i++) {
        now += q_pow(A[i], MOD - 2) * (i + 1) % MOD;
        now %= MOD;
        tot += now;
        tot %= MOD;
    }

    for(int i = 0, j = 0; i < M; i++) {
        while(j < N && a[j].first <= B[i]) {
            j++;
        }

        int64_t delta = (((B[i] + 2) * psum2[j] % MOD) - psum3[j] + MOD) % MOD;
        delta += (B[i] + 1) * ((psum1[N] - psum1[j] + MOD) % MOD) % MOD;
        delta %= MOD;

        delta -= psum1[N];
        delta += MOD;
        delta %= MOD;
        std::cout << (tot + delta) % MOD << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
