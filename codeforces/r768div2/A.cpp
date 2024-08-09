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
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    auto solve = [](std::vector<int> a, std::vector<int> b) {
        int n = a.size();
        for(int i = 0; i < n; i++) {
            if(b[i] > a[i]) {
                std::swap(a[i], b[i]);
            } 
        }
        
        return (*std::max_element(a.begin(), a.end())) * (*std::max_element(b.begin(), b.end()));
    };

    int ans = std::min(solve(A, B), solve(B, A));

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
