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

    int64_t ans = 0;
    int d = 0;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            d = std::max(d, A[i - 1] - A[i]); 
        }
    }

    if(d == 0) {
        std::cout << (int64_t)(N + 1) * N / 2 << '\n';
        return;
    }
    
    std::vector<std::pair<int, int>> a;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            int l = i;
            int r = i;
            while(r + 1 < N && A[r] + d > A[r + 1]) {
                if(A[r] > A[r + 1]) {
                    std::cout << 0 << '\n';
                    return;
                }
                r += 1;
            }
            a.emplace_back(l, r);
            i = r;
        }
    }
    
    ans = d;
    for(int k = d + 1; k <= N; k++) {
        std::vector<std::pair<int, int>> n_a;
        bool end = false;
        for(auto [l, r] : a) {
            if(!n_a.empty() && l <= n_a.back().second) {
                continue;
            }

            while(r + 1 < N && A[r] + k > A[r + 1]) {
                if(A[r] > A[r + 1]) {
                    end = true;
                    break;
                }
                r += 1;
            } 
            n_a.emplace_back(l, r);
        } 
        if(end) {
            break;
        }
        ans += k;
        std::swap(a, n_a);
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
