#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> CA(N);
    std::vector<int> B(N);
    std::vector<int> CB(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> CA[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> CB[i];
    }

    std::vector<std::multiset<int>> c(N * 2 + 1);
    std::vector<int> can_swap(N * 2 + 1, 0);
    for(int i = 0; i < N; i++) {
        c[CA[i]].insert(A[i]);
        c[CB[i]].insert(B[i]);
        can_swap[CB[i]] = 1;
    }

    int pre = 0;
    for(int i = 0; i < N; i++) {
        if(can_swap[CA[i]]) {
            auto it = c[CA[i]].lower_bound(pre);

            if(it == c[CA[i]].end()) {
                std::cout << "No" << '\n';
                return;
            }

            pre = *it;
            c[CA[i]].erase(it);
        } else {
            if(A[i] < pre) {
                std::cout << "No" << '\n';
                return;
            }
            pre = A[i];
        }
    }

    std::cout << "Yes" << '\n';
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
