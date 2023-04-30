#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using LL = long long;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    LL ans = 0LL;

    sort(A.begin(), A.end());

    for(int i = 0; i < N;) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
    
        int len = i - j;
        if(len >= 3) {
            ans += 1LL * len * (len - 1) * (len - 2);
        }
    }

    std::map<LL, int> m;
    for(int i = 0; i < N; i++) {
        m[A[i]] += 1;
    }

    for(auto [k, v] : m) {
        std::vector<int> fact;
        for(int f = 1; f * f <= k; f++) {
            if(k % f == 0) {
                fact.push_back(f); 
                if(k / f != f) {
                    fact.push_back(k / f);
                }
            }
        }

        for(int f : fact) {
            if(f == k) {
                continue;
            }

            if(m.find(f) != m.end() && m.find(1LL * k / f * k) != m.end()) {
                ans += 1LL * v * m[f] * m[1LL * k / f * k];
            }
        }
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
