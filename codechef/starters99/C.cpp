#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::map<int, int> m1;
    std::map<int, int> m2;
    for(int i = 0; i < N; i++) {
        m1[std::min(A[i], B[i])] += 1;
        m2[A[i]] += 1;
        m2[B[i]] += 1;
    }

    int ans = (int)1e9;
    for(int i = 0; i < N; i++) {
        int a = A[i];
        int b = B[i];

        if(--m1[std::min(a, b)] == 0) {
            m1.erase(std::min(a, b)); 
        }
        if(--m2[a] == 0) {
            m2.erase(a);
        }
        if(--m2[b] == 0) {
            m2.erase(b);
        }

        if(a >= m1.rbegin()->first) {
            auto it = m2.upper_bound(a);
            if(it != m2.begin()) {
                it--;
                ans = std::min(ans, a - it->first);
            }
        }

        if(b >= m1.rbegin()->first) {
            auto it = m2.upper_bound(b);
            if(it != m2.begin()) {
                it--;
                ans = std::min(ans, b - it->first);
            }
        }

        m1[std::min(a, b)] += 1;
        m2[a] += 1;
        m2[b] += 1;
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
