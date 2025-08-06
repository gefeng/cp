#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    auto solve = [](std::vector<int> a, std::vector<int> b) {
        int n = a.size();
        
        std::vector<int> common(n + 1, 0);
        int min_v = n + 1;
        for(int i = 0; i < n; i++) {
            if(a[i] == b[i]) {
                common[a[i]] = 1;
            }
        }

        for(int i = 0; i <= n; i++) {
            if(!common[i]) {
                min_v = std::min(min_v, i);
            }
        }

        if(min_v == n + 1) {
            return n + 1;
        }

        for(int i = 0; i < n; i++) {
            if(a[i] == min_v) {
                std::swap(a[i], b[i]);
            }
        }

        int x = n + 1;
        for(int i = 0; i < n; i++) {
            if(b[i] > min_v && !common[b[i]]) {
                x = std::min(x, b[i]); 
            } 
        }

        for(int i = 0; i < n; i++) {
            if(b[i] == x) {
                std::swap(a[i], b[i]);
            }
        }

        std::ranges::sort(a);
        std::ranges::sort(b);

        a.erase(std::unique(a.begin(), a.end()), a.end());
        b.erase(std::unique(b.begin(), b.end()), b.end());
        
        int mex_a = 0;
        int mex_b = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == mex_a) {
                mex_a += 1;
            } else {
                break;
            }
        }

        for(int i = 0; i < b.size(); i++) {
            if(b[i] == mex_b) {
                mex_b += 1;
            } else {
                break;
            }
        }

        return std::max(mex_a, mex_b);
    };

    std::cout << std::min(solve(A, B), solve(B, A)) << '\n';
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
