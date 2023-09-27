#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t MAX = (int64_t)1e9;

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::map<int64_t, int64_t> m1;
    std::map<int64_t, int64_t> m2;
    int x = N;
    for(int f = 2; f * f <= x; f++) {
        if(x % f == 0) {
            int cnt = 0;
            while(x % f == 0) {
                x /= f;
                cnt += 1;
            }
            m1[f] = cnt;
        }
    }

    if(x > 1) {
        m1[x] = 1;
    }

    m2 = std::map<int64_t, int64_t>(m1);

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        if(T == 1) {
            int X;
            std::cin >> X;
            x = X;
            for(int f = 2; f * f <= x; f++) {
                if(x % f == 0) {
                    int cnt = 0;
                    while(x % f == 0) {
                        x /= f;
                        cnt += 1;
                    }
                    m2[f] += cnt;
                }
            }
            if(x > 1) {
                m2[x] += 1;
            }

            bool res = true;
            std::map<int64_t, int64_t> m;
            for(auto [v, f] : m2) {
                m[f + 1] += 1;
            }

            std::map<int64_t, int64_t> mm;
            for(auto [v, c] : m) {
                int x = v;
                for(int f = 2; f * f <= x; f++) {
                    if(x % f == 0) {
                        int cnt = 0;
                        while(x % f == 0) {
                            x /= f;
                            cnt += 1;
                        }
                        mm[f] += cnt * c;
                    }
                }
                if(x > 1) {
                    mm[x] += c;
                }
            }

            for(auto [v, f] : mm) {
                if(m2.find(v) == m2.end() || m2[v] < mm[v]) {
                    res = false;
                    break;
                }
            }

            std::cout << (res ? "YES" : "NO") << '\n';
        } else {
            m2 = std::map<int64_t, int64_t>(m1); 
        }
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
