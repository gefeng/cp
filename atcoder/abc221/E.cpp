#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;
using LL = long long;

const LL MOD = 998244353LL;

struct fenwick_tree {
    int sz;
    vector<LL> t;

    fenwick_tree(int n) : sz(n + 1) {
        t.resize(sz, 0);
    }

    void update(int i, LL x) {
        for(i += 1; i < sz; i += i & -i) {
            t[i] += x;
            t[i] %= MOD;
        }
    }

    LL query(int i) {
        LL res = 0LL;
        for(i += 1; i > 0; i -= i & -i) {
            res += t[i];
            res %= MOD;
        }
        return res;
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

void compress(vector<int>& a) {
    set<int> s(a.begin(), a.end());
    int id = 0;
    map<int, int> m;
    for(int x : s) {
        m[x] = id++; 
    } 

    for(int& x : a) {
        x = m[x];
    }
}

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    compress(A);

    vector<LL> p_2(N + 1);
    vector<LL> ip_2(N + 1);
    p_2[0] = 1LL;
    for(int i = 1; i <= N; i++) {
        p_2[i] = p_2[i - 1] * 2LL;
        p_2[i] %= MOD;
    }
    
    LL inv = q_pow(2LL, MOD - 2LL);
    ip_2[0] = 1LL;
    for(int i = 1; i <= N; i++) {
        ip_2[i] = ip_2[i - 1] * inv;
        ip_2[i] %= MOD;
    }

    fenwick_tree ft(N + 5);
    LL ans = 0LL;
    for(int i = 0; i < N; i++) {
        if(i > 0) {
            ans += p_2[i - 1] * ft.query(A[i]) % MOD;
            ans %= MOD;
        } 

        ft.update(A[i], ip_2[i]);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
