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

    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    if(N == 1) {
        std::cout << "Yes" << '\n';
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int> ans(N);
    for(int i = 0; i < N; i++) {
        std::set<int> s;
        for(int k = 0; k < 30; k++) {
            int x = i == 0 ? A[i][1] : A[i][0];
            if(x & (1 << k)) {
                s.insert(k);
            }
        }

        for(int j = 0; j < N; j++) {
            if(i != j) {
                for(int k = 0; k < 30; k++) {
                    if((A[i][j] & (1 << k)) == 0 && s.find(k) != s.end()) {
                        s.erase(k); 
                    }         
                }
            }
        }

        for(int b : s) {
            ans[i] |= 1 << b; 
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i != j && (ans[i] | ans[j]) != A[i][j]) {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    std::cout << "Yes" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
