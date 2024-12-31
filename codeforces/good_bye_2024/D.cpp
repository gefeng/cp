#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t MOD = int64_t(998244353);

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
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<std::pair<int, int>> A(N);
    std::vector<std::pair<int, int>> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i].first;
        B[i].second = i;
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    std::map<int, std::pair<int, int>> ma;
    std::map<int, std::pair<int, int>> mb;
    std::vector<int> pos_a(N, -1);
    std::vector<int> pos_b(N, -1);
    
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i].first == A[j].first) {
            pos_a[A[i].second] = i;
            i += 1;
        }
        ma[A[j].first] = {j, i - 1};
    }
    
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && B[i].first == B[j].first) {
            pos_b[B[i].second] = i;
            i += 1;
        }
        mb[B[j].first] = {j, i - 1};
    }
    
    int64_t ans = 1;
    for(int i = 0; i < N; i++) {
        ans *= std::min(A[i].first, B[i].first);
        ans %= MOD;
    }

    auto swap_a = [&](int l, int r) {
        pos_a[A[l].second] = r;
        pos_a[A[r].second] = l;
        std::swap(A[l], A[r]);
    };

    auto swap_b = [&](int l, int r) {
        pos_b[B[l].second] = r;
        pos_b[B[r].second] = l;
        std::swap(B[l], B[r]);
    };

    std::cout << ans << ' ';
    for(int i = 0; i < Q; i++) {
        int T, P;
        std::cin >> T >> P;
        P -= 1;
        if(T == 1) {
            int p = pos_a[P];
            int v = A[p].first;
            int nv = v + 1;

            auto [l, r] = ma[v];
            
            if(nv <= B[r].first) {
                ans += ans * q_pow(v, MOD - 2) % MOD;
                ans %= MOD;
            }

            A[p].first = nv;
            if(l == r) {
                ma.erase(v);    
            } else {
                swap_a(p, r);
                ma[v].second -= 1;
            }
            if(ma.find(nv) != ma.end()) {
                ma[nv] = {r, ma[nv].second};
            } else {
                ma[nv] = {r, r};
            }
        } else {
            int p = pos_b[P];
            int v = B[p].first;
            int nv = v + 1;

            auto [l, r] = mb[v];
            
            if(nv <= A[r].first) {
                ans += ans * q_pow(v, MOD - 2) % MOD;
                ans %= MOD;
            }

            B[p].first = nv;
            if(l == r) {
                mb.erase(v);    
            } else {
                swap_b(p, r);
                mb[v].second -= 1;
            }
            if(mb.find(nv) != mb.end()) {
                mb[nv] = {r, mb[nv].second};
            } else {
                mb[nv] = {r, r};
            }
        }

        std::cout << ans << " \n"[i == Q - 1];
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
