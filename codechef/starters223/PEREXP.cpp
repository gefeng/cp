#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> freq(N + 1, 0);
    for(int x : A) {
        if(++freq[x] > 2) {
            std::cout << 0 << '\n';
            return;
        }
    }

    int max_v = 0;
    for(int i = 1; i <= N; i++) {
        if(freq[i] == 2) {
            max_v = i;
        }
    }

    if(max_v == 0) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<int> divisors;
    for(int f = 1; f * f <= max_v; f++) {
        if(max_v % f == 0) {
            if(f > 1) {
                divisors.push_back(f);
            }
            if(max_v / f != f && max_v / f > 1) {
                divisors.push_back(max_v / f);
            }
        }
    }

    std::ranges::sort(divisors);

    int64_t ans = 0;
    for(int d : divisors) {
        int64_t cnt = 1;
        std::vector<int> a(freq);
        for(int x = N; x >= 1; x--) {
            if(a[x] == 2) {
                int now = x;
                while(a[now] > 1) {
                    if(now == 1) {
                        cnt = 0;
                        break;
                    }
                    if(now % d != 0) {
                        cnt = 0;
                        break;
                    }
                    a[now] -= 1;
                    now /= d;
                    if(++a[now] > 2) {
                        cnt = 0;
                        break;
                    }
                }
                if(cnt == 0) {
                    break;
                }
                cnt *= 2;
                cnt %= MOD;
            } else if(a[x] > 2) {
                cnt = 0;
                break;
            }
        } 
        ans += cnt;
        ans %= MOD;
    }

    std::cout << ans << '\n';
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
