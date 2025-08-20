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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> m1;
    std::map<int, int> m2;
    for(int i = 0; i < N; i++) {
        m1[A[i]] += 1;
    }

    for(auto [x, f] : m1) {
        m2[f] += 1;
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        char C;
        int X;
        std::cin >> C >> X;

        if(C == '+') {
            int f = m1[X];
            m1[X] += 1;
            if(--m2[f] == 0) {
                m2.erase(f);
            }
            m2[f + 1] += 1;
        } else {
            int f = m1[X];
            if(--m1[X] == 0) {
                m1.erase(X);
            }
            if(--m2[f] == 0) {
                m2.erase(f); 
            }
            if(f - 1) {
                m2[f - 1] += 1;
            }
        }

        if(m2.empty()) {
            std::cout << "NO" << '\n';
            continue;
        }

        auto [c, f] = *m2.rbegin();
        if(c < 4) {
            std::cout << "NO" << '\n';
            continue;
        }

        if(f > 1 || c > 7) {
            std::cout << "YES" << '\n';
            continue;
        }

        int side = c - 4 > 1 ? 1 : 0;

        auto it = std::prev(m2.end());
        if(m2.size() > 1) {
            it = std::prev(it); 
            if(it->first > 3) {
                std::cout << "YES" << '\n';
                continue;
            }
            if(it->first > 1) {
                side += it->second;
            }
        }

        if(m2.size() > 2) {
            it = std::prev(it);
            if(it->first > 1) {
                side += it->second;
            }
        }
        std::cout << (side > 1 ? "YES" : "NO") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
