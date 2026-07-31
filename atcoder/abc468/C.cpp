#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

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

    std::vector<int> p(N, 0);
    std::iota(p.begin(), p.end(), 1);

    int ans = 0; 
    do {
        if(p > A && p < B) {
            ans++;
        } 
    } while(std::next_permutation(p.begin(), p.end()));

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
