#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i]; 
    }

    std::vector<std::tuple<int, int, int>> B(Q);
    for(int i = 0; i < Q; i++) {
        auto& [r, x, idx] = B[i];
        std::cin >> r >> x;
        idx = i;
    }

    std::sort(B.begin(), B.end()); 
    
    std::vector<int> lis;
    std::vector<int> ans(Q, 0);
    for(int i = 0, j = 0; i < N; i++) {
        if(lis.empty() || A[i] > lis.back()) {
            lis.push_back(A[i]);
        } else {
            auto it = std::lower_bound(lis.begin(), lis.end(), A[i]);
            *it = A[i];
        }

        while(j < Q && std::get<0>(B[j]) == i + 1) {
            auto it = std::upper_bound(lis.begin(), lis.end(), std::get<1>(B[j])); 
            ans[std::get<2>(B[j])] = it - lis.begin();
            j += 1;
        }
    }

    for(int i = 0; i < Q; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
