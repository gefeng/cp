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
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int> psum(N + 1, 0);
    std::map<int, std::vector<int>> m;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] ^ A[i];
        sum ^= A[i];
        m[sum].push_back(i);
    }

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;
        
        sum = psum[R + 1] ^ psum[L]; 
        if(sum == 0) {
            std::cout << "Yes" << '\n';
            continue;
        }

        if(R - L + 1 == 2) {
            std::cout << "No" << '\n';
            continue;
        }
        
        auto it1 = std::lower_bound(m[psum[L]].begin(), m[psum[L]].end(), R);
        if(it1 != m[psum[L]].begin()) {
            it1--;
            int p1 = *it1;
            if(p1 > L) {
                auto it2 = std::lower_bound(m[psum[R + 1]].begin(), m[psum[R + 1]].end(), L);
                if(it2 != m[psum[R + 1]].end() && *it2 + 1 < R) {
                    int p2 = *it2 + 1;
                    if(p1 >= p2) {
                        std::cout << "Yes" << '\n';
                        continue;
                    } 
                }
            }
        }

        std::cout << "No" << '\n';
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
