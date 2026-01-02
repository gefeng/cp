#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(1e9) + 7;

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int64_t lcm(int64_t a, int64_t b) {
    return a * b / gcd(a, b);
}

std::vector<int> phi_1_to_n(int n) {
    std::vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> divisors(N + 1);
    for(int c = 1; c <= N - 2; c++) {
        int x = N - c;
        for(int f = 1; f * f <= x; f++) {
            if(x % f == 0) {
                divisors[x].push_back(f);
                if(f != x / f) {
                    divisors[x].push_back(x / f);
                }
            }
        } 
    }     

    std::vector<int> coprime_pairs = phi_1_to_n(N + 1);

    int64_t ans = 0;
    for(int c = 1; c <= N - 2; c++) {
        int x = N - c;
        for(int g : divisors[x]) {
            if((N - c) / g == 1) {
                continue;
            }
            int64_t l = lcm(c, g) % MOD;
            int64_t quantity = coprime_pairs[(N - c) / g];
            ans += l * quantity % MOD;
            ans %= MOD;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
