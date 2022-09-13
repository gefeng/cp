#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const int MOD = (LL)1e9 + 7;

void run_case(int T) {
    int N, Q;
    cin >> N;

    vector<pair<LL, LL>> A(N);
    for(int i = 0; i < N; i++) {
        LL X, Y;
        cin >> X >> Y;
        A[i] = {X, Y};
    }

    cin >> Q;
    vector<pair<LL, LL>> B(Q);
    for(int i = 0; i < Q; i++) {
        LL X, Y;
        cin >> X >> Y;
        B[i] = {X, Y};
    }

    LL sum_x = 0LL;
    LL sum_xsq = 0LL;
    LL sum_y = 0LL;
    LL sum_ysq = 0LL;
    
    for(int i = 0; i < N; i++) {
        sum_x += A[i].first;
        sum_x %= MOD;
        sum_y += A[i].second;
        sum_y %= MOD;

        sum_xsq += A[i].first * A[i].first % MOD;
        sum_xsq %= MOD;
        sum_ysq += A[i].second * A[i].second % MOD;
        sum_ysq %= MOD;
    }

    LL ans = 0LL;
    for(pair<LL, LL>& q : B) {
        LL x = q.first;
        LL y = q.second;

        ans += (x * x % MOD) * N % MOD;
        ans %= MOD;
        ans += sum_xsq;
        ans %= MOD; 
        ans = ans - (2 * x * sum_x % MOD) + MOD;
        ans %= MOD;

        
        ans += (y * y % MOD) * N % MOD;
        ans %= MOD;
        ans += sum_ysq;
        ans %= MOD; 
        ans = ans - (2 * y * sum_y % MOD) + MOD;
        ans %= MOD;
    }

    cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
