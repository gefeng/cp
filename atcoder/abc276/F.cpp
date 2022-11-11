#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = 998244353LL;
const int MAX = (int)2e5;

struct fenwick_tree {
    int sz;
    vector<LL> t;

    fenwick_tree(int n) : sz(n + 5) {
        t.resize(sz, 0LL); 
    }

    void update(int i, int x) { 
        for(++i; i < sz; i += i & -i) {
            t[i] += x;
            t[i] %= MOD;
        }
    }

    LL query(int i) {
        LL res = 0LL;
        for(++i; i > 0; i -= i & -i) {
            res += t[i];
            res %= MOD;
        }
        return res;
    }

    LL query(int l, int r) {
        return (query(r) - query(l - 1) + MOD) % MOD;
    }
};

LL q_pow(LL x, LL y) {
    LL res = 1LL;
    while(y) {
        if(y & 1LL) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1LL;
    }
    return res;
}

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    fenwick_tree ft_1(MAX + 1);
    fenwick_tree ft_2(MAX + 1);
    
    vector<LL> dp(N + 1, 0LL);
    for(int i = 1; i <= N; i++) {
        dp[i] += dp[i - 1];
        dp[i] %= MOD;

        LL x = ft_1.query(A[i - 1], MAX) + (ft_2.query(A[i - 1] - 1) * A[i - 1] % MOD);
        x %= MOD;

        dp[i] += 2LL * x;
        dp[i] %= MOD;

        dp[i] += A[i - 1];
        dp[i] %= MOD;

        ft_1.update(A[i - 1], A[i - 1]);
        ft_2.update(A[i - 1], 1);
        
        LL y = q_pow(1LL * i, MOD - 2LL);
        y *= y;
        y %= MOD;
        
        cout << dp[i] * y % MOD << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
