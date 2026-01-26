#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t MOD = static_cast<int64_t>(1e9) + 7;
constexpr int MAX = static_cast<int>(2e5);

std::vector<std::vector<int>> pf(MAX + 1);

void run_case() {
    int N, C;
    std::cin >> N >> C;

    std::string S;
    std::cin >> S;

    if(S[0] == '0' || S.back() == '0') {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> factors;
    for(int f = 2; f * f <= C; f++) {
        if(C % f == 0) {
            while(C % f == 0) {
                factors.push_back(f);
                C /= f;
            }
        }
    }
    if(C > 1) {
        factors.push_back(C);
    }

    std::ranges::sort(factors);
    std::map<int, int> m;

    int size = factors.size();
    for(int i = 0; i < size; ) {
        int j = i;
        while(i < size && factors[i] == factors[j]) {
            i += 1;
        }
        m[factors[j]] = i - j;
    }

    if(S[1] == '?') {
        S[1] = '0';
    }
    
    int64_t ans = 1;
    for(int i = N - 1; i > 0; i--) {
        int n = i + 1;
        if(S[i - 1] == '0') {
            for(int f : pf[n - 2]) {
                if(m.find(f) != m.end()) {
                    if(--m[f] == 0) {
                        m.erase(f);
                    }
                }
            }
            if(m.empty()) {
                std::cout << -1 << '\n';
                return;
            }
            ans *= n - 2;
        } else if(S[i - 1] == '1' || i == 1) {
            if(m.find(2) != m.end()) {
                if(--m[2] == 0) {
                    m.erase(2);
                }
            }
            if(m.empty()) {
                std::cout << -1 << '\n';
                return;
            }
            ans *= 2;
        }
        ans %= MOD;
    }

    if(m.find(2) == m.end() || m.size() > 1) {
        for(int i = 3; i < N; i++) {
            if(S[i - 1] == '?') {
                ans *= 2;
                ans %= MOD;
            }
        }
    } else {
        int cnt = 0;
        for(int i = 3; i < N; i++) {
            if(S[i - 1] == '?') {
                int n = i + 1;
                if(pf[n - 2][0] == 2) {
                    if(--m[2] == 0) {
                        m.erase(2);
                    }
                    ans *= 2;
                    ans %= MOD;
                } else {
                    cnt += 1;
                }
            }
            if(m.empty()) {
                std::cout << -1 << '\n';
                return;
            }
        }
        
        int t = std::max(0, cnt - (m[2] - 1));
        for(int i = 3; i < N; i++) {
            if(S[i - 1] == '?') {
                int n = i + 1;
                if(pf[n - 2][0] != 2) {
                    if(t) {
                        ans *= n - 2;
                        ans %= MOD;
                        t -= 1;
                    } else {
                        ans *= 2;
                        ans %= MOD;
                    }
                }
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<int> is_prime(MAX + 1, 1);
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            for(int j = i + i; j <= MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    std::vector<int> min_p(MAX + 1, static_cast<int>(2e9));
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            for(int j = i; j <= MAX; j += i) {
                min_p[j] = std::min(min_p[j], i);
            }
        } 
    }

    for(int i = 2; i <= MAX; i++) {
        int x = i;
        while(x != 1) {
            int p = min_p[x];
            while(x % p == 0) {
                pf[i].push_back(p);
                x /= p;
            }
        }
    }

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
