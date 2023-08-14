#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    if(A.front() == A.back()) {
        std::cout << -1 << '\n'; 
        return;
    }

    std::vector<int> b;
    std::vector<int> c;
    for(int i = 0; i < N; i++) {
        if(A[i] != A.back()) {
            b.push_back(A[i]);
        } else {
            c.push_back(A[i]);
        }
    }

    if(c.empty()) {
        std::cout << -1 << '\n';
    } else {
        int n = b.size();
        int m = c.size();
        std::cout << n << ' ' << m << '\n';
        for(int i = 0; i < n; i++) {
            std::cout << b[i] << " \n"[i == n - 1];
        }

        for(int i = 0; i < m; i++) {
            std::cout << c[i] << " \n"[i == m - 1];
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
