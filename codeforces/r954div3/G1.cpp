#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, std::map<int, int>> m1;
    std::map<int, std::map<int, int>> m2;
    for(int i = 0; i < N; i++) {
        int g = gcd(i + 1, A[i]);
        int a = A[i] / g;
        int b = (i + 1) / g;

        m1[a][b] += 1;
        m2[b][a] += 1;
    }

    int64_t ans = 0;
    for(auto& [bi, m] : m2) {
        for(int aj = bi; aj <= N; aj += bi) {
            if(m1.find(aj) == m1.end()) {
                continue;
            }

            for(auto [ai, f1] : m) {
                for(auto [bj, f2] : m1[aj]) {
                    if(ai % bj == 0) {
                        if(ai == aj && bi == bj) {
                            ans += (int64_t)f1 * f2 - f1;
                        } else {
                            ans += (int64_t)f1 * f2;
                        }
                    }
                }
            }
        }
    }

    ans /= 2;

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
