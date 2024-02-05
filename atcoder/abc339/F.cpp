#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <ctime>

constexpr int64_t MIN = (int64_t)1e9;
constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> primes;
    std::srand(std::time(NULL));

    auto is_prime = [](int64_t x) {
        for(int64_t f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                return false;
            }
        } 
        return true;
    }; 

    while(primes.size() < 20) {
        int64_t p = (rand() % MIN) + MIN;
        
        if(is_prime(p)) {
            primes.push_back(p);
        }
    }

    auto mod = [](std::string& s, int64_t p) {
        int n = s.size();
        int64_t res = 0;
        for(int i = 0; i < n; i++) {
            int d = s[i] - '0';
            res = res * 10 + d;
            res %= p;
        }
        return res;
    };

    auto solve = [&]() {
        int64_t ans = INF;

        for(int64_t p : primes) {
            int64_t cnt = 0;
            std::vector<int64_t> a(N);
            std::map<int64_t, int> m;
            for(int i = 0; i < N; i++) {
                int64_t x = mod(A[i], p);
                m[x] += 1;
                a[i] = x;
            }

            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    int64_t prod = a[i] * a[j] % p;
                    if(m.find(prod) != m.end()) {
                        cnt += m[prod];
                    }
                }
            }

            ans = std::min(ans, cnt);
        }

        return ans;
    };

    std::cout << solve() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
