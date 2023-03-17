#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

const LL MOD = 1000000007LL;

LL gcd(LL a, LL b) {
    if(a == 0LL) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    cin >> N;

    vector<LL> A(N);
    vector<LL> B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    map<pair<LL, LL>, int> m;
    for(int i = 0; i < N; i++) {
        if(A[i] == 0LL && B[i] == 0LL) {
            m[{0LL, 0LL}] += 1;
        } else if(A[i] == 0LL) {
            m[{0LL, 1LL}] += 1;
        } else if(B[i] == 0LL) {
            m[{1LL, 0LL}] += 1;
        } else {
            LL g = gcd(abs(A[i]), abs(B[i]));
            m[{A[i] / g, B[i] / g}] += 1;
        }
    }

    vector<LL> p_2(N + 1, 1LL);
    for(int i = 1; i <= N; i++) {
        p_2[i] = p_2[i - 1] * 2LL % MOD;
    }

    LL zero = 0LL;
    if(m.find({0LL, 0LL}) != m.end()) {
        zero = m[{0LL, 0LL}];
        m.erase({0LL, 0LL});
    }

    LL ans = 1LL;
    while(!m.empty()) {
        auto it1 = m.begin();
        pair<LL, LL> k1 = it1->first;
        int f1 = it1->second; 

        if(k1.first == 0LL || k1.second == 0LL) {
            pair<LL, LL> k2 = {k1.first ^ 1, k1.second ^ 1};
            if(m.find(k2) != m.end()) {
                int f2 = m[k2];
                ans *= (((p_2[f1] + p_2[f2]) % MOD) - 1LL + MOD) % MOD;
                ans %= MOD;
                m.erase(k2);
            } else {
                ans *= p_2[f1];
                ans %= MOD;
            }
        } else {
            pair<LL, LL> k2 = {-k1.first, -k1.second};
            if(m.find(k2) != m.end()) {
                f1 += m[k2];
                m.erase(k2);
            }

            pair<LL, LL> k3 = {k1.second, -k1.first};
            int f2 = 0;
            if(m.find(k3) != m.end()) {
                f2 += m[k3]; 
                m.erase(k3);
            } 

            pair<LL, LL> k4 = {-k1.second, k1.first};
            if(m.find(k4) != m.end()) {
                f2 += m[k4];
                m.erase(k4);
            } 

            if(f2) {
                ans *= (((p_2[f1] + p_2[f2]) % MOD) - 1LL + MOD) % MOD;
                ans %= MOD;
            } else {
                ans *= p_2[f1];
                ans %= MOD;
            }
        }

        m.erase(k1);
    }

    ans += zero;
    ans %= MOD;

    ans -= 1LL;
    ans += MOD;
    ans %= MOD;
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
