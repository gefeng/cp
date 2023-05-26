#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MOD = 998244353LL;

void run_case() {
    int K;
    std::cin >> K;

    int n = 1;
    for(int i = 0; i < K; i++) {
        n *= 2; 
    }

    std::vector<int> A(n);
    for(int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    std::vector<LL> p2(n + 1, 1LL);
    std::vector<LL> fact(n + 1, 1LL);
    for(int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2LL % MOD;
        fact[i] = fact[i - 1] * i % MOD;
    }

    std::vector<int> t(A); 
    
    LL ans = 1LL;
    for(int j = K; j > 0; j--) {
        int l = p2[j - 1];
        int r = p2[j];

        int sz = t.size();
        int a = 0;      // count how many undetermined losing teams
        int b = 0;      // count how many pairs has 2 undetermined teams
                        // 2 ^ b * a!
        for(int i = 0; i < sz; i += 2) {
            if(t[i] > l && t[i] <= r && t[i + 1] > l && t[i + 1] <= r) {
                std::cout << 0 << '\n'; 
                return;
            }

            if(t[i] > 0 && t[i] <= l && t[i + 1] > 0 && t[i + 1] <= l) {
                std::cout << 0 << '\n';
                return;
            }

            if(t[i] == -1 && t[i + 1] == -1) {
                b += 1;
                a += 1;
            } else if(t[i] == -1 && t[i + 1] <= l) {
                a += 1; 
            } else if(t[i + 1] == -1 && t[i] <= l) {
                a += 1;
            }
        }

        ans *= p2[b] * fact[a] % MOD;
        ans %= MOD;

        std::vector<int> nt;
        for(int i = 0; i < sz; i += 2) {
            if(t[i] == -1 && t[i + 1] == -1) {
                nt.push_back(-1);
            } else if(t[i] == -1) {
                if(t[i + 1] > l && t[i + 1] <= r) {
                    nt.push_back(-1);
                } else {
                    nt.push_back(t[i + 1]);
                }
            } else if(t[i + 1] == -1) {
                if(t[i] > l && t[i] <= r) {
                    nt.push_back(-1);
                } else {
                    nt.push_back(t[i]);
                }
            } else {
                nt.push_back(std::min(t[i], t[i + 1]));
            }
        }

        std::swap(t, nt);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
