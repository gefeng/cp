#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(1e9);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> suffix_min(N, INF);
    for(int i = N - 1; i >= 0; i--) {
        suffix_min[i] = i == N - 1 ? A[i] : std::min(suffix_min[i + 1], A[i]);
    } 

    int ans = 1;
    int max_v = 0;
    for(int i = 0; i < N - 1; i++) {
        max_v = std::max(max_v, A[i]); 
        if(max_v < suffix_min[i + 1]) {
            ans += 1;
        }
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
